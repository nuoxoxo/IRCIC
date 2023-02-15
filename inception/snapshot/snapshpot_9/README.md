CMD vs. ENTRYPOINT \
Why no port mapping in Compose
When to pass in the .env
Why "daemon off"

	# Where the server starts and with wich file
	root /var/www/html/;
	# Sets the index file that opens up when the web site is accessed
	index index.php index.html;
	# Receives a request to the URI that matches the block in the location, try the $uri first, return file if is present,
	# if not, try index.php. If all fails return 404
	try_files $uri $uri/ /index.php?$args;
	}

	# For request with uri that ending with a .php ext
	location ~ \.php$ {

