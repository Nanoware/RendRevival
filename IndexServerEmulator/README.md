## Index Server Emulator

This simple script is meant to run on Heroku to provide an API endpoint for servers to connect to so their presence can be advertised on the in-game server browser.

The magic that lets game servers then find the index server can be done in one of two ways:

* Use a DLL that is hardwired to a particular endpoint (akin to the vanilla game and the long-gone original index server) - use `dll-hardcoded-index-server` which will then point at https://rendapi.herokuapp.com
* Use an `Authentication.ini` configured to hit a particular endpoint - use `dll-configurable-index-server-url`

In theory anybody should be able to stand up a new index server with the included script, and point the game at it. Further details would be nice to add at some point but at least as of this writing we have a nice server running thanks to Farlier!
