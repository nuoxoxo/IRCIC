# Dockerfile vs. docker-compose.yml
### Difference:
- __Dockerfile__ is used to build images.
- __docker-compose.yaml__ file is used to run images. 
### How to run:
- The Dockerfile runs with the <kbd> docker build </kbd> command.
- The docker-compose.yaml uses the <kbd> docker-compose up </kbd> command.
### Commands 
&nbsp;&nbsp;for docker-compose.yml 
```j
docker-compose up -d --build
docker-compose up -d

docker-compose down
docker exec -it nginx_simple sh
```
