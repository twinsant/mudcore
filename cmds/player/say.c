inherit CORE_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
    arg = arg || "...";
    msg("MAG", "$ME said: " + arg, me);

    return 1;
}

int help(object me)
{
    write(@HELP
Command : say [content]

This command allows you to chat with other players in the room.

HELP );
    return 1;
}
