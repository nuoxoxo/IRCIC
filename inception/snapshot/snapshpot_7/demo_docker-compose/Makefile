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
	@# if [ `docker ps -qa` = "" ]; then docker stop `docker ps -qa`; endif
	@ docker stop `docker ps -qa`
	@ docker system prune --all --force --volumes
	@ docker network prune --force
	@ docker volume prune --force

f	: fclean

.PHONY	: all build down re clean fclean
