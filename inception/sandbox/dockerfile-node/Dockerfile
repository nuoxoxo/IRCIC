# syntax=docker/dockerfile:1

FROM node:18-alpine
	# -> download the node:18-alpine image

WORKDIR /app

COPY . .
	# -> why

RUN yarn install --production

CMD ["node", "src/index.js"]

EXPOSE 3000

# then do :
	# cd app/
	# docker build -t _project_ .
	# docker run -dp 443:443 _project_
	# > browser: http://localhost:443

# -t : --tag
# .  : look for Dockerfile in the current directory

# -d : --detached
# -p : port mapping btw host's port 443 to container’s port 443

