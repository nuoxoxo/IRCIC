ARG		NODE_VERSION=8.11-slim
FROM		node:$NODE_VERSION

USER		nuoxoxo
WORKDIR		$workdirectory

LABEL		"about"="just a label"

ENV		workdirectory /home/uxn

RUN		mkdir /project
VOLUME		/project

COPY		package.json .

RUN		ls -ll && \
		npm install

RUN		useradd nuoxoxo && \
		mkdir -p $workdirectory && \
		chown nuoxoxo $workdirectory
    
ADD		index.js .

RUN		ls -l

EXPOSE		4430

ENTRYPOINT	["node"]
