## Customizing Rend via DLL tweaking

These two files are used by Farlier to adjust the main DLL we customize to get basic things added like flags for setting your character name without being able to use the character creator.

What makes it work is how Unreal Engine (which powers Rend and many other games) exposes certain things commonly between projects, as well as allowing game hooks at various phases of running the game. With a bit of cleverness you can make things work in a "blank" project of sorts then just take the things you need and shove them into some relevant file in the Rend directory.

Details beyond that would be nice to get added here at some point :-)
