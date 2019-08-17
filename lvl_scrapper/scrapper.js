const puppeteer = require('puppeteer');

const prompt = require('prompt');

const prompt_attributes = [
  {
    name: 'username',
    hidden: false,
  },
  {
    name: 'password',
    hidden: true
  },
];

prompt.start();

prompt.get(prompt_attributes, function (err, result) {
  if (err) {
    console.log(err);
    return 1;
  }else {
    const username = result.username;
    const password = result.password;

    console.log('Fetching from the Matrix ... Please wait');
    mainScrap(username, password);
  }
});

const preparePageForTests = async (page) => {
  const userAgent = 'Mozilla/5.0 (X11; Linux x86_64)' +
    'AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.39 Safari/537.36';
  await page.setUserAgent(userAgent);

  await page.evaluateOnNewDocument(() => {
    Object.defineProperty(navigator, 'webdriver', {
      get: () => false,
    });
  });

  await page.evaluateOnNewDocument(() => {
    window.navigator.chrome = {
      runtime: {},
    };
  });

  await page.evaluateOnNewDocument(() => {
    const originalQuery = window.navigator.permissions.query;
    return window.navigator.permissions.query = (parameters) => (
      parameters.name === 'notifications' ?
        Promise.resolve({state: Notification.permission}) :
        originalQuery(parameters)
    );
  });

  await page.evaluateOnNewDocument(() => {
    Object.defineProperty(navigator, 'plugins', {
      get: () => [1, 2, 3, 4, 5],
    });
  });

  await page.evaluateOnNewDocument(() => {
    Object.defineProperty(navigator, 'languages', {
      get: () => ['en-US', 'en'],
    });
  });
};


async function mainScrap(userName, password) {
  let url = "https://the-matrix.le-101.fr/";
  const browser = await puppeteer.launch({
    headless: true,
    ignoreHTTPSErrors: true
  });
  const page = await browser.newPage();
  await preparePageForTests(page);

  await login(page, url, userName, password);

  await page.waitForSelector('.userImg', { visible: true, timeout: 0 });

  let imgList = await page.evaluate( () => {
    let ret = [];
    let users = document.querySelectorAll(".userImg");
    let c = document.querySelectorAll(".userImg").length;
    let i = 0;
    while (i < c) {
      ret.push(users[i].src);
      i++;
    }
    return ret;
  });

  let i = 0;
  let c = imgList.length;
  let ret = [];

  while (i < c) {

    let imgLink = imgList[i];
    page.evaluate( (imgLink) => {
      let img = document.querySelector(`.userImg[src='${imgLink}']`);
      img.click();
    }, imgLink);


    await page.waitForSelector(`.statValue`, { visible: true, timeout: 0 }).then(async () => {

          await page.evaluate(() => {
            return new Promise((resolve, reject) => {

              if (document.getElementsByClassName('bannerLogo')[0] === undefined && document.getElementsByClassName("statValue")[2].innerText === "0") {
                resolve({
                  name: document.getElementsByClassName('userName')[0].innerText,
                  lvl: parseFloat(document.getElementsByClassName('statValue')[3].innerText)
                });
              } else {
                reject();
              }
            });
          })
            .then((userDetails) => {
                ret.push(userDetails);
            })
            .catch(() => console.log('...'));
      });
      i++;
  }

  console.table(ret.sort((a, b) => {
      if (a.lvl > b.lvl) {
        return -1;
      } else {
        return 1;
      }
  }));
  process.exit(0);
}

let login = async (page, url, userName, password) => {

    await page.goto(url);
    await page.evaluate(async () => {
      document.getElementsByClassName('loginButton')[0].click();
    });
    await page.waitForSelector('#user_login', { visible: true, timeout: 0 });
    await page.evaluate((userName, password) => {
      document.getElementById('user_login').value = userName;
      document.getElementById('user_password').value = password;
      document.getElementsByClassName('btn btn-login')[0].click();
      return document.getElementById('user_login').value
    }, userName, password);
};
