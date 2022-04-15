/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: gender.c
Description: 角色性别人称相关模拟函数
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
string pronoun(int pronoun_number, mixed arg)
{
    if( objectp(arg) )
        arg = arg->query("gender");

    switch(pronoun_number)
    {
        case 1:
            return "I";

        case 2:
            return "You";

        case 3:
            switch( arg )
            {
                case MALE: return "He";
                case FEMALE: return "She";
                default:
                    return "It";
            }
        default:
            error("Unknown pronoun\n");
    }
}
