## $\color {CarnationPink} \text { Cleanup } $

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



![](https://i.imgur.com/LeybD6x.png)



## $\color {Apricot} \text { .env } $
```coffee
DOMAIN_NAME=nuxu.42.fr

DB_HOST=mariadb
DB_NAME=wordpress
DB_ROOT_PASSWORD=4242

DB_ADMIN=mariadb
DB_ADMIN_PASSWORD=4242

WP_ADMIN=nuxu_adm
WP_ADMIN_MAIL=nuxu_adm@42.fr
WP_ADMIN_PASSWORD=4242

WP_USER=nuxu
WP_USER_PASSWORD=4242
WP_MAIL=nuxu@42.fr
```



![](https://i.imgur.com/EFKvFLx.png)



## $\color {Yellow} \text { Progress } $
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




## $\color {Goldenrod} \text { Latest } $
- "Welcome to nginx" homepage problem: [stoflow](https://stackoverflow.com/questions/70454890/running-wordpress-on-docker-compose-nginx-mysql-and-php)
- About - version: '[3](https://docs.docker.com/compose/compose-file/compose-file-v3/)'







__test list__
- todo...
- <kbd>RUN</kbd> docker exec -it wordpress ps aux | grep 'php'
- <kbd>RUN</kbd> docker exec -it wordpress php -v
- <kbd>RUN</kbd> docker exec -it wordpress php -m
- <kbd>TRY</kbd> `https://127.0.0.1`
- <kbd>RUN</kbd> docker exec -it mariadb mysql -u root
  - <kbd>SQL</kbd> show databases;


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
