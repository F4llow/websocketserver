# websockterserver
its a websocket server written in c. run the executable (after compiling it yourself, i just included mine for fun) and then run "wscat -c ws://localhost:8080" from 1+ terminals to chat between them (npm install -g wscat)

install libwebsockets using: sudo apt-get install libwebsockets-dev
wss.c is the c program. i compiled it using "gcc -o wss wss.c -lwebsockets"
therefore wss is the executable

