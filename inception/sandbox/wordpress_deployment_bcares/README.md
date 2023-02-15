:pencil: - What is docker-compose

- docker-compose is a cli tool
- Compose is written in Python
- It can be download using pip or apt-get
- Compose runs multiple Docker containers as a single device
- Each container is a service

:memo: - Set up environment \
_&nbsp;&nbsp;&nbsp;&nbsp;see [bottom](#bottom)_

:closed_book: - Set up WordPress 

- _Goal_
  - Set up a compose environment for a WordPress project)_

- _Plan_
  - Deploy the 'WordPress' PHP application as a device of docker containers
  - This application is run by Compose, with supports from 2 other apps
  - Web server : Nginx
  - MySQL database : MariaDB
  - Each app is run on its own container

- _Scheme_ 
  - -nginx : Use the official 'nginx: latest' docker image
  - -MySQL : Use the most recent version of official MariaDB container
  - -WordPress : Use latest wordpress with latest PHP-FPM from docker-hub
  - Use a regular linux user for the setup -> won't run docker as root


:speak_no_evil: - Create a linux user, add user to docker group
```
useradd -m -s /bin/bash nuoxoxo passwd 4242
usermod -a -G docker nuoxoxo systemctl restart docker

su - nuoxoxo 
```
:open_file_folder: - Create the project directory
```
mkdir -p wordpress-compose 
cd wordpress-compose/
touch docker-compose.yml
mkdir -p nginx/
mkdir -p db-data/
mkdir -p logs/nginx/
mkdir -p wordpress/
```
:incoming_envelope: -_Scheme_ 
- docker-compose.yml : the Brain
- -nginx : Contains ngx.conf, virtual host, ...
- -db-data : Mount all '/var/lib/mysql' data here
- -wordpress : Contain all WordPress files
- -logs : Store application log, nginx, mariadb, php-fpm, ...


:ship: - _Config the compose.yml ( w/ ngx only )_
```
nginx:
    image: nginx:latest
    ports:
        - '80:80'
    volumes:
        - ./nginx:/etc/nginx/conf.d
        - ./logs/nginx:/var/log/nginx
        - ./wordpress:/var/www/html
    links:
        - wordpress
    restart: always
```


:scroll: - _Configure WordPress_ 
```
vim nginx/wordpress.conf
```
```
server {

  listen 80;
  server_name wp-hakase.co;
  root /var/www/html;
  index index.php;


  access_log /var/log/nginx/hakase-access.log;
  error_log /var/log/nginx/hakase-error.log;


  location / {
    try_files $uri $uri/ /index.php?$args;
  }


  location ~ \.php$ {
    try_files $uri =404;
    fastcgi_split_path_info ^(.+\.php)(/.+)$;
    fastcgi_pass wordpress:9000;
    fastcgi_index index.php;
    include fastcgi_params;
    fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
    fastcgi_param PATH_INFO $fastcgi_path_info;
  }

}
```


--- 
<a name="bottom"></a>
##### Set up environment 
- 1st, install docker
```sh
# Upd. Ubuntu repo
sudo apt-get update sudo apt-get upgrade

# Get docker, enable auto-boot
sudo apt-get install -y docker.io
systemctl start docker systemctl enable docker
docker run hello-world
```
- then, install compose
```
sudo apt-get install -y python python-pip
pip install docker-compose
docker-compose -v
```
