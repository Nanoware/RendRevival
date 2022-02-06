## Rend Revival - Only Almost Dead!

These files help in the configuration and management of Rend in its afterlife of sorts. While you can no longer play Rend normally (or even acquire it by regular means) after the game and later its index/auth server was sunset, with some minimal tweaks you can indeed still play.

More could be done here but to get started here are some minimal pointers. To get more join the Last Hope community at https://discord.gg/gUJyZEXxyq which also deserves full credit for all the work that went into these customizations, particularly Farlier for reverse engineering some bits related to the index server and the DLL customization process.


### Server

To run a server you need to get the "Rend Server" via the Tools section on Steam. Let it install on a Windows system normally. You'll need to port forward `7777` and `15000` by regular means if you're hosting behind a typical residential router, and have those ports open on your firewall software for UDP at least. LAN play may also be possible with port `14001` available locally?

To run the server in LAN mode include the `-LANGAME` parameter - it may also be necessary to include `-multihome=1.2.3.4` with a suitable IP for your network.

To run the server on the internet you _must_ customize at least one game file to avoid being hardwired to the old defunct index server, otherwise your game server can't show up in the in-game server browser. Unsure if you'd be able to use a client with `-connect=1.2.3.4:7777` with an entirely vanilla server ...

The main customization applies to `PhysX3Cooking_x64.dll` which lives in `<REND dir>\Engine\Binaries\ThirdParty\PhysX3\Win64\VS2015` - many variants of this file have been supplied over time, see the involved process in the DllPatchingProcess directory and pick from one of the `dll-` folders in this repo.

To run the game server find your way to `<Steam library dir>\steamapps\common\Rend Server\Otherlands\Binaries\Win64` and execute `OtherlandsServer-Win64-Shipping.exe -NoEAC -log BeaconPort=15000 Port=7777` adjusting the ports as needed, but being mindful that the in-game server browser _only_ will try to connect to game port `7777` (direct connection via client CLI args can use other ports). You should not need to run this from an admin-elevated command prompt.


### Client

On the client side you need to acquire the game then run it with one or more command line arguments. These can be added in Steam or via Windows Command Prompt, or even Powershell.

In the most basic setup you may be able to use `-LANGAME` to simply play on the local area network in your home.

More typically you'll want to connect to a remote server. One somewhat awkward way to extend a LAN to remote players is through a VPN service like ZeroTier, which was the first successful way to play remotely without the index server, but it suffered from a certain degree of complexity and performance problems.

The better way involves customizing one or more game files. Like with the server the main one is `PhysX3Cooking_x64.dll` - see IndexServerEmulator's readme for additional details of DLL variants specific to whether or not you're attempting to use a custom ("rogue") index server provided by you or the Last Hope community.

To finally launch the game there are new (and old?) command line arguments available, particularly as character creation may be unavailable:

* `-NoEAC` - disable the anti-cheat. This must _always_ be enabled, either using this argument or picking No EAC when launching from Steam. Otherwise the modified DLL will be caught as a problem.
* `-playername=SOMENAME` - set your character name
* `-faction=#` - pick your faction, either `1`, `2` , or `3` (Revenant, Conclave, or Order)
* `-console` - if you want to see some basic game logging during startup and connecting in a separate window
* `-connect=1.2.3.4:7777` - with a target server IP or URL, to connect directly - if this works the main game menu will appear for a moment but automatically continue to the loading screen (if connecting works!)

So as an example to connect directly to the main Last Hope community server you'd use a command like the following: `-noeac -playername=GenericViking -faction=2 -console -connect=rend.terasology.net:7777` (this should work via Steam launch by simply plugging it into Rend -> Properties -> General -> Launch Options - although you may still have to pick no EAC in a popup)

If you attempt to connect via server browser from in-game be sure that your filter is set wide and includes the No EAC flag. If a server is listed but the detail panel just has a progress indicator that keeps going odds are that port forwarding / firewalling is getting in the way. If the server does show details immediately but the "Join" button does nothing it may be that the game server is on a non-standard port and can't be reached via server browser.


### Settings

To configure the server gameplay settings you mainly need to look at `config.ini` in the root dir for "Rend Server" and `Game.ini` which lives deeper in at `Rend Server\Otherlands\Saved\Config\WindowsServer\`

Two sets are included in this repo for the two most common setups for Last Hope community servers. Suggestions via PR welcome!
