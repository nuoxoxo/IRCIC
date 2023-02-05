name	:= demo_docker-nginx-html

all	:
	@ echo "launch $(name)... "
	@ docker-compose -f ./docker-compose.yml up -d

build	:
	@ echo "building $(name)... "
	@ docker-compose -f ./docker-compose.yml up -d --build

down	:
	@ echo "stopping ${name}... "
	@ docker-compose -f ./docker-compose.yml down

re	: down
	@ echo "rebuild $(name)... "
	@ docker-compose -f ./docker-compose.yml up -d --build

clean	: down
	@ echo "cleaning $(name)... "
	@ docker system prune -a

f	: fclean

fclean	:
	@ echo "Total clean of all configurations docker "
	@ docker stop $$(docker ps -qa)
	@ docker system prune --all --force --volumes
	@ docker network prune --force
	@ docker volume prune --force

.PHONY	: all build down re clean fclean
