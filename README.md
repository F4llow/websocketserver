# websockterserver
its a websocket server written in c. run the executable (after compiling it yourself, i just included mine for fun) and then run "wscat -c ws://localhost:8080" from 1+ terminals to chat between them (npm install -g wscat)

install libwebsockets using: sudo apt-get install libwebsockets-dev
wss.c is the c program. i compiled it using "gcc -o wss wss.c -lwebsockets"
therefore wss is the executable

notes:
so i am learning c and stumbled across websockets after skipping my latin class this morning

ofc i heard the term before but i know a lot more now than when i had heard it the first time

so i then went into the usual rabbit hole

i had never heard of http long polling

if you dont know what this is look it up and then compare it to websockets

i read articles, watching youtube videos, et cetera (latin reference lol)

so then im  like ok i want to do some thing with websockets and c rn

so i was like lets make a basic chat application

i know that i need a websocket server (wss) and then i want to have different users connect to this wss and all send messages betwen each other

this is great

so im doing all this research and looking at all these different libraries

then im like ok i hav seen libwebsockets all over lets try this

quite a few places are saying that the documentation is bad and the examples are hard to read/understand

there was also the " well IIIIII had no problem with it" on yc news

relax dud

so i look into it right

then i open a chatgpt prompt

here is the first message: so dont give me any code but put me on the right track for this project i want to work on. so i want to learn abt networking and do it in c. ik quite a bit about both. so the project that i want to do is to make a sort of realtime chat thing. my vision is to make a realtime chat where it automatically updates with the text messages. i dont care about making it public or anything. maybe just for now something that i culd hav like 2 separate terminals open and communicate between the two. havent thought too much about that. so i think and correct me if im wrong i need to make a websocket server that each person has to connect to. first by this http request to actaully establish the connection, then transfer the protocol to websockets. this will allow for realtime updating instead of the http/http long polling things

so im asking lots of high level questions and still doing the researching and trying to understand the random examples

for all ik my c knowledge culd just b terrible (it is)

but like

idk

so im a litle frustrated right

and im like ah fuck it

yo gpt just give me the code

fast forward like 5 messages

i compile it and it works perfectly

i also made a few changes and additional features such as a "From X:" where X is the number that they are in the connection order since the server started

here is what it looks like, just a little local chatting between two terminals

![image](https://github.com/user-attachments/assets/31b89506-6fa1-4d4e-a754-86b9020e8bb4)

it would not be hard to host on some vm at all

then just connect and hav ur buddy connect and do little things like that

it would probs be better/safer/more efficient/etc in another language

but i just hav this sort of pull to c

the fact u can have an entire wws in a single executable file is just the coolest thing ever

and c/c++ is what NASA uses

i really have to learn embedded systems

my gosh

anyways

our jobs are not done for because everyone is retarted

our jobs as in swe

we have the most powerful tool in history chatgpt

man am i glad i had stackoverflow and documentation to learn to how solve problems myself (+ the actaul ppl who ask those questions and answer them lol)

but you know what i mean

its a skill to b able to do that (that i have :P)

but the ease of gpt

holy fuck

all you have to have is a sort of high level understanding and then you can make anything

i fully believe if you gave me some standard idea i could get a prototype in no time

i was vague in the above line because of how broad a project can b

o u want to make a website with some backend and then you want to have user logins and then make a marketplace

ok

as long as u have this good computer intuition/know commands/file structures/asdf

you can do it

extremely easily

who cares if every website looks the same

i will just use my boy mr buffett's web design to stand out

minus the geico and jewelery ads you sellout (i would do the same)

but ya

chatgpt is so powerful but very few ppl have this "skill", the skill of good computer intuition and coming up with potential problems/solutions/etc on the fly

that is something i am so good at, my gosh

once ppl figure out how chatgpt works, this is what will set apart a good programmer from everyone else

literaly, since anyone (with basic file structure/command understanding) can get whatever they want up and running

man i need to learn everything

but what is the point of learning anything more than system design, etc if chatgpt can do it

disclaimer that i have gpt4 lol :D

but naw just kidding, i will learn everything

or else the gp q irl might come in clutch fr (good luck deciphering this u normie)

wtf am i even talking like this

i swear im smart and normal and spell well (i won the spelling bee in fifth grade)

i can also type well and i just find this easy to get thoughts out

asdf

its fine
