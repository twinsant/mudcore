// 本文件必须包含在 <globals.h> **底部**
#ifndef MUDCORE_H
#define MUDCORE_H

#define ROOT_UID      "Root"
#define BACKBONE_UID  "Backbone"

/* 系统目录 */
// 如果核心框架目录不是默认，需要在 <globals.h> 中定义
#ifndef CORE_DIR
#define CORE_DIR "/mudcore/"
#endif
// 存档目录，应该在 <globals.h> 中定义
#ifndef DATA_DIR
#define DATA_DIR "/data/"
#endif
// 日志目录，应该在 <globals.h> 中定义
#ifndef LOG_DIR
#define LOG_DIR "/log/"
#endif

/* 核心对象 */
#define CORE_MASTER_OB      CORE_DIR "system/kernel/master"
#define CORE_SIMUL_EFUN_OB  CORE_DIR "system/kernel/simul_efun"
#define CORE_VOID_OB        CORE_DIR "system/object/void"
#define CORE_LOGIN_OB       CORE_DIR "system/object/login"
#define CORE_USER_OB        CORE_DIR "system/object/user"

/* 守护进程 */
#define CORE_CHANNEL_D      CORE_DIR "system/daemons/channel_d"
#define CORE_CHINESE_D      CORE_DIR "system/daemons/chinese_d"
#define CORE_COMMAND_D      CORE_DIR "system/daemons/command_d"
#define CORE_DBASE_D        CORE_DIR "system/daemons/dbase_d"
#define CORE_EMOTE_D        CORE_DIR "system/daemons/emote_d"
#define CORE_LOGIN_D        CORE_DIR "system/daemons/login_d"
#define CORE_VIRTUAL_D      CORE_DIR "system/daemons/virtual_d"
#define CORE_TIME_D         CORE_DIR "system/daemons/time_d"

/* inherit 特性文件 */
#define CORE_CLEAN_UP       CORE_DIR "inherit/clean_up"
#define CORE_COMMAND        CORE_DIR "inherit/command"
#define CORE_DBASE          CORE_DIR "inherit/dbase"
#define CORE_MESSAGE        CORE_DIR "inherit/message"
#define CORE_MOVE           CORE_DIR "inherit/move"
#define CORE_NAME           CORE_DIR "inherit/name"
#define CORE_OBSAVE         CORE_DIR "inherit/obsave"
#define CORE_ROOM           CORE_DIR "inherit/room"
#define CORE_SAVE           CORE_DIR "inherit/save"

/* 其他 */
#ifndef HTTP_PORT
#define HTTP_PORT   8000
#endif

#ifndef WIZARD
#define WIZARD  "ivy"
#endif

#ifndef MOTD
#define MOTD    CORE_DIR "system/etc/motd"
#endif

#ifndef CHANNEL_D
#define CHANNEL_D   CORE_CHANNEL_D
#endif

#ifndef CHINESE_D
#define CHINESE_D   CORE_CHINESE_D
#endif

#ifndef COMMAND_D
#define COMMAND_D   CORE_COMMAND_D
#endif

#ifndef DBASE_D
#define DBASE_D     CORE_DBASE_D
#endif

#ifndef EMOTE_D
#define EMOTE_D     CORE_EMOTE_D
#endif

#ifndef LOGIN_D
#define LOGIN_D     CORE_LOGIN_D
#endif

#ifndef TIME_D
#define TIME_D      CORE_TIME_D
#endif

#ifndef VIRTUAL_D
#define VIRTUAL_D   CORE_VIRTUAL_D
#endif

#ifndef SIMUL_EFUN_OB
#define SIMUL_EFUN_OB    CORE_SIMUL_EFUN_OB
#endif

#ifndef MASTER_OB
#define MASTER_OB   CORE_MASTER_OB
#endif

#ifndef LOGIN_OB
#define LOGIN_OB    CORE_LOGIN_OB
#endif

#ifndef USER_OB
#define USER_OB     CORE_USER_OB
#endif

#ifndef VOID_OB
#define VOID_OB     CORE_VOID_OB
#endif

#endif
