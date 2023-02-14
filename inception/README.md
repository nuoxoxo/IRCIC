## $\color {Goldenrod} \text { Cleanup } $

```
docker stop $(docker ps -qa); docker rm $(docker ps -qa); docker rmi $(docker images -qa); docker volume rm $(docker volume ls -q); docker network rm $(docker network ls -q) 2>/dev/null 

$$$$

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
