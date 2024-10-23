#ifndef CHARCOL_CHAT_H
#define CHARCOL_CHAT_H

#include <stddef.h>
#include <stdint.h>
#include <pthread.h>

#ifndef CHC_CHAT_BUF_MAX
#define CHC_CHAT_BUF_MAX 16
#endif

#ifndef CHC_CHAT_MSG_MAX
#define CHC_CHAT_MSG_MAX 248
#endif

/** Chat Message */
struct chc_chat_msg {
        char content[CHC_CHAT_MSG_MAX];
        size_t length;
};

/** Chat Ring Buffer */
struct chc_chat_buf {
        struct chc_chat_msg messages[CHC_CHAT_BUF_MAX];
        size_t first;
        size_t size;
        pthread_mutex_t mutex;
};

/** Chat User */
struct chc_chat_user {
        uint64_t uid;
        double rate;
        struct chc_chat_buf *buffer;
};

/** User Linked List Node */
struct chc_chat_unode {
        struct chc_chat_user *user;
        struct chc_chat_unode *next;
};

/** User Linked List */
struct chc_chat_ulist {
        struct chc_chat_unode *first, *last;
        size_t size;
};

/** Chat Room */
struct chc_chat_room {
        struct chc_chat_ulist *users;
};

/** Chat Configuration */
struct chc_chat_cfg {
        float max_rate;
};

/** Chat Context */
struct chc_chat_ctx;

/** Create a new chat context. */
struct chc_chat_ctx *chc_chat_create_ctx(
        struct chc_chat_cfg *cfg);

/** Get room by uid. */
struct chc_chat_room *chc_chat_get_room(
        struct chc_chat_ctx *ctx, 
        const uint64_t uid);

/** Receive messages for user. */
int chc_chat_recv(
        struct chc_chat_user *user,
        struct chc_chat_msg *messages,
        const size_t count);

/** Send a message to the chat room. */
int chc_chat_send(
        struct chc_chat_room *room, 
        struct chc_chat_room *user,
        struct chc_chat_msg *message);

#endif