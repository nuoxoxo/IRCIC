## Latest
- "Welcome to nginx" homepage problem 
  - [stof](https://stackoverflow.com/questions/70454890/running-wordpress-on-docker-compose-nginx-mysql-and-php)
- About - version: '[3](https://docs.docker.com/compose/compose-file/compose-file-v3/)'
- sandboxes
  - [bmurth](https://medium.com/swlh/wordpress-deployment-with-nginx-php-fpm-and-mariadb-using-docker-compose-55f59e5c1a)
  - [bcares](https://bobcares.com/blog/docker-compose-nginx-php-fpm-mysql-wordpress/)
  - [kjuell](https://www.digitalocean.com/community/tutorials/how-to-install-wordpress-with-docker-compose)


## $\color {Goldenrod} \text { Cleanup } $

```sh
# oneline
docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null 

# spread
docker stop $(docker ps -qa)
docker rm $(docker ps -qa)
docker rmi $(docker images -qa)
docker volume rm $(docker volume ls -q)
docker network rm $(docker network ls -q) 2>/dev/null 
```

## $\color {CarnationPink} \text { Progress } $
- mariaDB <kbd> done draft </kbd> 
  - snapshot 8 _not created_ - __test:__ <kbd> needed </kbd>
  - _logs_
    - \+. Dockerfile 
    - \+. conf/generate_db.sh
    - _mod._ srcs/docker-compose.yml
- nginx <kbd> fi. </kbd> 
  - snapshot 7 - __test:__ <kbd> OK </kbd>
  - _logs_
    - \+. ngx Dockerfile (7)
    - \+. Makefile (6)
    - \+. certificate & local domain (5)



__test list__
- todo...
- <kbd>RUN</kbd> docker exec -it wordpress ps aux | grep 'php'
- <kbd>RUN</kbd> docker exec -it wordpress php -v
- <kbd>RUN</kbd> docker exec -it wordpress php -m
- <kbd>TRY</kbd> `https://127.0.0.1`
- <kbd>RUN</kbd> docker exec -it mariadb mysql -u root
  - <kbd>SQL</kbd> show databases;

__for snapshot 9::fixed__
```
DOMAIN_NAME=nuxu.42.fr

DB_HOST=mariadb
DB_NAME=wordpress
DB_ROOT_PASSWORD=4242

DB_ADMIN=mariadb
DB_ADMIN_PASSWORD=4242

WP_ADMIN=nuxu
WP_ADMIN_MAIL=nuxu@42.fr
WP_ADMIN_PASSWORD=4242

WP_USER=user
WP_USER_PASSWORD=4242
WP_MAIL=user@42.fr

```


__deprecated, snapshot 7__  
```sh
# .env

DOMAIN_NAME=nuxu.42.fr

CERT_=./requirements/tools/nuxu.42.fr.crt
KEY_=./requirements/tools/nuxu.42.fr.key

DB_NAME=wordpress
DB_ROOT=rootpass
DB_USER=wpuser
DB_PASS=wppass
```

__makefile sampler__
```
all	:
	@ mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
	@ docker compose -f srcs/docker-compose.yml up --build -d

down	:
	@ docker compose -f srcs/docker-compose.yml down

clean	: down
	@ docker system prune -af --volumes
	@ docker volume rm $$(docker volume ls -q)

fclean	: clean
	@ sudo rm -rf /home/${USER}/data

f	: fclean

re	: fclean all

.PHONY	: all down clean fclean re
```



## $\color{Goldenrod } \text { Misc. } $
- inception [Git](https://github.com/nuoxoxo/ircci/tree/main/inception)
- DEMO
  - _Demo_ - http-server
  - _Demo_ - <kbd> php -S localhost:8080 -t . </kbd>
  - _Demo using docker-compose_ - ngx, html & .YML
  - sandbox for Dockerfile(s)
- :star: Eval :: to read

## &nbsp;

![](https://i.imgur.com/B26PCcR.png)
