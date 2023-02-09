#!/bin/bash

mkdir project
mkdir project/srcs
mkdir project/srcs/requirements
mkdir project/srcs/requirements/tools
mkdir project/srcs/requirements/bonus # bonus

touch project/Makefile
touch project/srcs/docker-compose.yml

# .env
touch project/srcs/.env
echo "DOMAIN_NAME=nuxu.42.fr" > project/srcs/.env
echo "CERT_=./requirements/tools/nuxu.42.fr.crt" >> project/srcs/.env
echo "KEY_=./requirements/tools/nuxu.42.fr.key" >> project/srcs/.env
echo "DB_NAME=wordpress" >> project/srcs/.env
echo "DB_ROOT=rootpass" >> project/srcs/.env
echo "DB_USER=wpuser" >> project/srcs/.env
echo "DB_PASS=wppass" >> project/srcs/.env
# nginx

mkdir project/srcs/requirements/nginx
touch project/srcs/requirements/nginx/Dockerfile

# nginx -> conf & tools

mkdir project/srcs/requirements/nginx/tools
mkdir project/srcs/requirements/nginx/conf
touch project/srcs/requirements/nginx/conf/nginx.conf
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
