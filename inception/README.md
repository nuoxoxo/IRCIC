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
$ groups UXN
$ usermod -aG docker UXN
$ groups UXN
$ su UXN
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
% run startx
% startx run {?????????????????}
```

### 3 _(none)_
# 4 - Docker preconfiguration

- Demo 1 - _http-server_ :: html
- Demo 2 - _docker-compose_ :: nginx, html
  - to retry and flip this red ball :red_circle:
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
echo "DOMAIN_NAME=<UXN>.42.fr" > project/srcs/.env
echo "CERT_=./requirements/tools/<UXN>.42.fr.crt" >> project/srcs/.env
echo "KEY_=./requirements/tools/<UXN>.42.fr.key" >> project/srcs/.env
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
___mariadb___ and ___wordpress___ will have only one config each :yellow_circle:
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

# 5 - Certificates & local domain
