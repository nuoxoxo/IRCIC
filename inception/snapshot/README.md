for snapshot 9::fixed
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
makefile sampler
```
all :
		mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
		docker compose -f srcs/docker-compose.yml up --build -d

down :
		docker compose -f srcs/docker-compose.yml down

clean :	down
		docker system prune -af --volumes
		docker volume rm $$(docker volume ls -q)

fclean : clean
		sudo rm -rf /home/${USER}/data

f :		fclean

re : fclean all

.PHONY:	all down clean fclean re

```
