# Subject
- choose btw Alpine or Debian
- write 3 Dockerfile, one per service
  - call these Dockerfiles one by one in Makefile via _docker-compose.yml_ 
- set up the following 3 Docker containers:
  - nginx (choose btw TLSv1.2 or TLSv1.3)
  - wordpress + php-fpm (installation + configuration)
  - mariadb (w/o nginx)
- set up the following 2 volumes:
  - 1st volume for wordpress database
  - 2nd volume for wordpress website files
- set up _docker-network_
  - goal: establish connection btw containers
- learn the forbidden patches:
  - `tail -f` 
  - bridge instead of tail -f, bash, sleep infinity, while true, host, --link, links
- {\*} container must reboot in case of crash
- {\**} what are daemons, how to use and whether we should use 'em
- In wordpress there must be 2 users
  - one of them is admin but w/o admin in their username
- all volumes will be available in <kbd> /home/{login}/data </kbd> in the hostmachine docker
- set up the domain name so it points to the local IP address
  - {login}.42.fr
- {\*} no `latest` tag
- {\**} there should not be any password in any Dockerfile
- the nginx container must be the only entrypoint into the infrastructure 
  - via the port 443 only
  - using the TLSv1.2 or TLSv1.3 protocol
```sh
$> ls -alR
total XX
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 .
drwxrwxrwt 17 wil wil 4096 avril 42 20:42 ..
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Makefile
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 srcs
./srcs:
total XX
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 ..
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 docker-compose.yml
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .env
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 requirements
./srcs/requirements:
total XX
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 bonus
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 mariadb
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 nginx
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 tools
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 wordpress
./srcs/requirements/mariadb:
total XX
drwxrwxr-x 4 wil wil 4096 avril 42 20:45 .
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 conf
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Dockerfile
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .dockerignore
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 tools
[...]
./srcs/requirements/nginx:
total XX
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 conf
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Dockerfile
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .dockerignore
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 tools
[...]
$> cat srcs/.env
DOMAIN_NAME=wil.42.fr
# certificates
CERTS_=./XXXXXXXXXXXX
# MYSQL SETUP
MYSQL_ROOT_PASSWORD=XXXXXXXXXXXX
MYSQL_USER=XXXXXXXXXXXX
MYSQL_PASSWORD=XXXXXXXXXXXX
[...]
$>
```
