---
version: '3'

services:
  nginx:
    image: nginx:stable-alpine
    volumes:
      - ./public:/var/www/public
      - ./nginx/conf.d:/etc/nginx/conf.d/
    restart: unless-stopped
    ports:
      - "80:80"
    container_name: simple_nginx_html
---

# :yellow_circle: \*Parsing a yaml metadata block 
(at the top of a md)
# :yellow_circle: Dockerfile vs. docker-compose.yml
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
# :yellow_circle: First 5 lines of a Dockerfile 
```dockerfile
# syntax=docker/dockerfile:1
FROM    alpine:3.15
LABEL   org.opencontainers.image.authors=nuoxoxo
LABEL   org.opencontainers.image.source=https://github.com/nuoxoxo/IRCCI
LABEL   org.opencontainers.image.version=0.1.0
```
