find . -type f -name '*.sh' -exec basename {} \; | rev | cut -c4- | rev 
