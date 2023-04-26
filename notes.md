yeah I was just thinking for interaction, we can make it that pressing left
click or hitting space enters look mode. If you press space in look mode or
right click then you get a contextual menu where you can choose to shoot at them
or talk to them / whatever if you are close enough.
Look should use your previous direction to select where it's looking at at
first.
Then for inventory we have a button or pressing i, and when you select an item
you get a menu for whether you want to equip it or whatever. Similar things for 
character menu and equipment menu.


Ok what is the vision here? Originally this was gonna be my garbage island game
but I kind of stole that idea for the other thing so I feel like this should be
something else. Also that was rather complex.
However, what is it that I really want from a roguelike game? I would kind of
like one that feels like a roguelite with a story. As in you feel like you are
playing zelda one or something except you can level up until you die.

Now, Ideally I would also like to make this game more like a level/scenario
editor than just a specific game, because I think that would be cool. Imagine
if there was like an online thing where you can download a new scenario and
play it. It would somehow tell you exactly how big they are etc.

Levels can either be hand drawn or generated or a mixture of both. The way this
works is in the level editor you create a level, then you can set algorithms
to be run on it, so essentially if you want a generated level then you are just
setting it's size, then setting algorithms to run, if you want a hand made level
then you make it. You could hypothetically run algorithms on hand made levels 
too like adding grass to a field or something but it might be better to do that
by hand in practice idk. Hmm could be a lot of work by hand, algorithm might be
a good shout there.

Yeah I gotta say this sounds pretty sweet. To keep down duplicated effort and
file size, the base game can also come with something like a standard library of
enemies weapons etc etc.

So the level editor is just a way of starting up the program essentially, and it
will need to have passed to it a scenario file and the specific level file you
want to edit. This way you will have access to all the necessary scenario data
like the available level processing algorithms.

stuff to implement:
    curses gui system

    scripting stuff since it's the basis of how the content gets in

    enemies and their data / stats

    pathing

    items and equipment

    figure out what to do about lighting

    level editor and associated shiet. Ideally make it use the mouse.

    figure out what to do about magic (Probably need to implement both ability
    style spells and magic items so that either can be used where appropriate.
    Spells should be scripted).