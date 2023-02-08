# Snapshot state:
DO
- <kbd> https://<span>127.0.0.1:443</span> </kbd> browser
- <kbd> https://<span>nuxu.42.fr</span> </kbd> startx gui
- `restart: always` (compose.yml)
  - Subject dictates that we must restart in case of crash
- `ports: "443:443"` (compose.yml)
  - What: Port Mapping 
  - Goal: to access the services inside Container
  - How: all requests made to the host port are
redirected to the Container
  - Syantax: `Host port` `:` `corresponding port in the docker Container`
  
```j
$ docker run -d -p 81:80 --name demo_container Demo
```
The _Demo_ container is launched with this docker command.
We can use Port 81 on the host machine to access the app.
The Demo server listens on port 80.
```bash
  # On the Host machine
$ curl http://localhost:81

# host port 81 to mapped to port 80 inside that container.
```


<!---

# 1 - download debian
no code
# 2 - setup
Update `apt` & get everything
```
$ su -
Password:
```

```
$ apt-get update -y
$ apt-get upgrade -y
```

```
$ apt install sudo vi vim ufw tree curl make
$ apt install wget git man-db openssh-server 
$ apt install -y docker docker-compose 
$ apt install -y openbox xinit kitty firefox-esr startx

$ man sudo
$ dpkg -l | grep sudo
```

SSH - _Install openssh-server_

```
$ apt install openssh-server
$ dpkg -l | grep ssh
$ systemctl status ssh
$ man ssh
```

Sudo - _/etc/sudoers_

```sh
$ vi /etc/sudoers

uxn    ALL(ALL:ALL) ALL
%sudo  ALL(ALL:ALL) ALL

# 1st ALL: this rule applies to all Hosts
# 2nd ALL: as a <usr>, i can run commands as all Users
# 3rd ALL: as a <usr> i run commands like all Groups
# last ALL: these rules apply to all commands
```

Sudo - _join sudo group_
```
$ groups uxn
$ usermod -aG docker uxn
$ groups uxn
$ su uxn
```

SSH - _/etc/ssh/sshd_config_

```
$ vi /etc/ssh/sshd_config
```

```j
Port 4343
PermitRootLogin yes
PasswordAuth yes
PubkeyAuth no
```

SSH - _grep port_ 

```
$ sudo service ssh restart
$ sudo service sshd restart

$ sudo grep -i port /etc/ssh/sshd_config

$ service ssh status
$ systemctl status ssh 
```
SSH - _UFW setup_
```
$ ufw status
$ ufw enable
$ ufw allow 4343
$ ufw allow 8080
$ ufw status
$ reboot 
```

SSH - _Set up port forwarding in VirtBox_

```
settings -> network -> Adapt 1
  box checked: NAT
  box checked: Cable connection
```
```
settings -> network -> advanced -> port forwarding -> Rule 1 
  Protocol: TCP 
  Host Port: 4242 
  Guest Port 4242
```
SSH - _get into vm via 4343_
```
$ ssh <usr>@<vmip> -p 4343
$ ssh -p 4343 <usr>@<vmip> 

$ logout 
$ exit
```

StartX ... :red_circle:
```
% sudo startx
```

### 3 _(none)_
# 4 - Docker preconfiguration

- Demo 1 
  - _http-server_ :: html
- Demo 2 
  - _docker-compose_ :: nginx, html
- make_dir.sh
  - remember to `chmod +x make_dir.sh`
```sh
#!/bin/bash

mkdir project
mkdir project/srcs
mkdir project/srcs/requirements
mkdir project/srcs/requirements/tools
mkdir project/srcs/requirements/bonus # bonus

touch project/Makefile
touch project/srcs/docker-compose.yml

# .env
```
```
touch project/srcs/.env
echo "DOMAIN_NAME=<uxn>.42.fr" > project/srcs/.env
echo "CERT_=./requirements/tools/<uxn>.42.fr.crt" >> project/srcs/.env
echo "KEY_=./requirements/tools/<uxn>.42.fr.key" >> project/srcs/.env
echo "DB_NAME=wordpress" >> project/srcs/.env
echo "DB_ROOT=rootpass" >> project/srcs/.env
echo "DB_USER=wpuser" >> project/srcs/.env
echo "DB_PASS=wppass" >> project/srcs/.env
```
```sh
# nginx

mkdir project/srcs/requirements/nginx
touch project/srcs/requirements/nginx/Dockerfile

# nginx -> conf & tools

mkdir project/srcs/requirements/nginx/tools
mkdir project/srcs/requirements/nginx/conf
touch project/srcs/requirements/nginx/conf/nginx.conf
```
```sh
# mariadb

mkdir project/srcs/requirements/mariadb
touch project/srcs/requirements/mariadb/Dockerfile

# mariadb -> conf & tools

mkdir project/srcs/requirements/mariadb/conf
touch project/srcs/requirements/mariadb/conf/create_db.sh
mkdir project/srcs/requirements/mariadb/tools
echo "" > project/srcs/requirements/mariadb/tools/.gitkeep

# mariadb -> .ignore

touch project/srcs/requirements/mariadb/.dockerignore
echo ".git" > project/srcs/requirements/mariadb/.dockerignore
echo ".env" >> project/srcs/requirements/mariadb/.dockerignore
echo ".git" > project/srcs/requirements/mariadb/.dockerignore
echo ".env" >> project/srcs/requirements/mariadb/.dockerignore
```
```sh
# wordpress

mkdir project/srcs/requirements/wordpress
touch project/srcs/requirements/wordpress/Dockerfile

# mariadb -> conf

mkdir project/srcs/requirements/wordpress/conf
touch project/srcs/requirements/wordpress/conf/wp-config-create.sh

# mariadb -> tools

mkdir project/srcs/requirements/wordpress/tools
echo "" > project/srcs/requirements/wordpress/tools/.gitkeep

# mariadb -> .ignore

touch project/srcs/requirements/wordpress/.dockerignore
echo ".git" > project/srcs/requirements/wordpress/.dockerignore
echo ".env" >> project/srcs/requirements/wordpress/.dockerignore
```

# Subject dictates
- Install a self-signed SSL certificate 
  - Why? - For local development, self-signed certificates are usually used
  - How? - Use ___mkcert___ 
- Run the app on port 443
- Use domain name <Username>.42.fr

# 5 - Certificates & local domain

Modify local domain
```
$ vi /etc/hosts
> 127.0.0.1    uxn.42.fr localhost

$ cd ~/demo_docker_compose && docker-compose up -d

(in vm window) 
> sudo startx
```
Get mkcert
```sh
$ sudo apt update -y
$ sudo apt install -y libnss3-tools
$ curl -s https://api.github.com/repos/FiloSottile/mkcert/releases/latest \
 | grep browser_download_url  | grep linux-amd64 \
 | cut -d '"' -f 4 | wget -qi - 

# On success

$ mv mkcert-v*-linux-amd64 mkcert
$ chmod a+x mkcert
$ sudo mv mkcert /usr/local/bin/

# Verify

$ mkcert --version
```
Get SSL Certificate
```
$ cd ~/project/srcs/requirements/tools/
$ mkcert uxn.42.fr
```
Change extensions for nginx server
```sh
$ mv uxn.42.fr-key.pem  uxn.42.fr.key
$ mv uxn.42.fr.pem      uxn.42.fr.crt
```
Reconfigure container to adapt HTTPS
- Edit ~/demo_docker_compose/nginx/conf.d/nginx.conf
- [Previous]
```sh
server {
    root    /var/www/public/html;
    location / {
        try_files $uri /index.html;
    }
}
```
- [Edit]
```sh
server {

	### Listen on http port
	### Listen on https port - ssl

	listen	80;
	listen	443 ssl;

	### Set domain of our site
	### Set root directory of our project

	root		/var/www/public/html;
	server_name	uxn.42.fr www.uxn.42.fr;

	### If redirection is needed (http -> https)

	#if ($scheme = 'http') {
	#    return 301 https://uxn.42.fr$request_uri;
	#}

	### Paths to certificates and keys

	ssl_certificate		/etc/nginx/ssl/uxn.42.fr.crt;
	ssl_certificate_key	/etc/nginx/ssl/uxn.42.fr.key;

	### Supported TLS Protocols

	ssl_protocols		TLSv1.2 TLSv1.3;

	### Caching options & timeouts

	ssl_session_timeout	10m;
	keepalive_timeout	70;

	### File extension that Server needs to find in ~/ (root)

	location / {
		try_files $uri /index.html;
	}
}

# note the 5 spots with username added in
```
Add another section with the keys
```
$ cd ~/simple_docker_compose/
$ docker-compose down
$ vi docker-compose.yml
```
- [Previous]
```
version: '3'

services:
  nginx:
    image: nginx:stable-alpine
    volumes:
      - ./public:/var/www/public
      - ./nginx/conf.d:/etc/nginx/conf.d/
    restart: unless-stopped
    ports:
      - "80:80"
    container_name: simple_nginx_html
```
- [Edit]
```j
version: '3'

services:
  nginx:
    image: nginx:stable-alpine
    volumes:
      - ./public:/var/www/public
      - ./nginx/conf.d:/etc/nginx/conf.d/
      - /home/${USER}/project/srcs/requirements/tools:/etc/nginx/ssl/  <--- 
    restart: unless-stopped
    ports:
      - "80:80"
    container_name: demo_docker_nginx_html
```
Run docker-compose again
```
$ docker-compose up -d

(in vm window) 
> sudo startx
```

	
# 6 - Makefile

```j
name	:= demo_docker-nginx-html

all	:
	@ echo " ➜ Build and launch ${name} ... "
	@ docker-compose -f ./docker-compose.yml up -d

build	: all

down	:
	@ echo " ➜ Stopping ${name} ... "
	@ docker-compose -f ./docker-compose.yml down

re	: down
	@ echo " ➜ Re-launch ${name} ... "
	@ docker-compose -f ./docker-compose.yml up -d --build

clean	: down
	@ echo " ➜ Cleaning up ${name} ... "
	@ docker system prune -a

fclean	:
	@ echo " ➜ Cleaning up "
	@ if [ `docker ps -qa` = "" ]; then \
		docker stop `docker ps -qa` \
	  endif
	@ docker system prune --all --force --volumes
	@ docker network prune --force
	@ docker volume prune --force

f	: fclean

.PHONY	: all build down re clean fclean
```


# 7 - $\color {BurntOrange} \text { Dockerfile - nginx } $

## __Dockerfile__
- Edit `~/project/srcs/requirements/nginx/Dockerfile`

FROM
```sh
FROM	alpine:3.16
```
RUN
```sh
RUN	apk update && apk upgrade && apk add --no-cache nginx
```
Container Port
```sh
EXPOSE	443
```
CMD
```sh
CMD	["nginx", "-g", "daemon off;"]
```

## __nginx.conf__ 
(Dockerfile won't work withou a config file)
- Edit `~/project/srcs/requirements/nginx/conf/nginx.conf`
```
server {

	listen	443 ssl;

	server_name	nuxu.42.fr www.nuxu.42.fr;
	root		/var/www/;
	index index.php index.html;

	ssl_certificate		/etc/nginx/ssl/nuxu.42.fr.crt;
	ssl_certificate_key	/etc/nginx/ssl/nuxu.42.fr.key;
	ssl_protocols		TLSv1.2 TLSv1.3;	
	ssl_session_timeout	10m;
	keepalive_timeout	70;

	### TESTING ...
	location / {
		try_files $uri /index.php?$args /index.html;
		add_header Last-Modified $date_gmt;
		add_header Cache-Control 'no-store, no-cache';
		if_modified_since off;
		expires off;
		etag off;
	}
	### (TESTING...)


	# location ~ \.php$ {
	# }
}
```

## Certificate recap
- cp  ~/project/srcs/requirements/tools/*  ~/project/srcs/requirements/nginx/tools/

--->
