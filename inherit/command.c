/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: command.c
Description: 角色指令控制接口
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <dbase.h>

/**
 * apply函数：如果用户对象中有process_input()，ＭＵＤＯＳ会将玩家所有输入传入这里
 * 如果本方法傳回一個字串，則此字串就取代使用者原先輸入的資料，用於往
 * 後的處理。如果本方法傳回一個非零、非字串的值，就不會再作處理。如果
 * 傳回零，則以原來輸入的資料作處理。在此之後才會看使用者輸入是否符合
 * add_actions 當時添加的動詞。
 */
mixed process_input(string arg)
{
    // debug_message(sprintf("%O process_input %s", this_object(), arg));
    // trime leading and ending spaces
    return COMMAND_D->default_alias(trim(arg));
}

nomask int command_hook(string arg)
{
    string verb;
    object me, file;
    object e;

    me = this_object();

    verb = query_verb();
    if (arg)
        arg = trim(arg);
    // debug_message(sprintf("command_hook %O %s: %s", me, arg, verb));
    if ((verb = trim(verb)) == "")
        return 0;

    e = environment();
    if (!arg && (objectp(e) && e->query("exits/" + verb)) &&
        objectp(file = COMMAND_D->find_command("go")) &&
        call_other(file, "main", me, verb))
        ;
    else if (objectp(e) && e->denied(verb))
    {
        write(sprintf("这里不能%s\n", verb));
        return 1;
    }
    else if (objectp(file = COMMAND_D->find_command(query_verb())) && call_other(file, "main", me, arg))
        ;
    else if (EMOTE_D->do_emote(me, verb, arg))
        ;
    else if (CHANNEL_D->do_channel(me, verb, arg))
        ;
    else
        return 0;

    return 1;
}

nomask void enable_living()
{
    object me = this_object();

    if (stringp(query("id")))
        set_living_name(query("id"));
    else
        set_living_name(query("name"));

    if (!query_temp("actived"))
    {
        enable_commands();
        parse_init();
        set_temp("actived", 1);
        add_action("command_hook", "", 1);
    }

    if (userp(me) && getuid(me) == WIZARD)
    {
        enable_wizard();
    }
}

nomask void disable_living(string type)
{
    if (query_temp("actived"))
    {
        disable_commands();
        delete_temp("actived");
    }
}
