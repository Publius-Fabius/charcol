
#include <stddef.h>

struct avl_tree;

struct chc_user {
        char *id;
        char *name;
};

struct chc_users {
        struct chc_user **array;
        size_t capacity;
        size_t size;
};

struct chc_room {
        struct chc_users *users;
};

struct chc_rooms {
        struct chc_room **array;
        size_t capacity;
        size_t size;
};

struct chc_complex {
        struct chc_rooms *rooms;
        struct avl_tree *users;
};

struct chc_message {
        struct chc_user *author;
        char *content;
};

#define CHC_BUFFER_MAX 32

struct chc_buffer {
        struct chc_message *messages[CHC_BUFFER_MAX];
};

/** Receive messages from the chat room. */
int chc_room_receive(
        struct chc_room *room, 
        struct chc_room *user,
        struct chc_buffer *buffer);

/** Send messages to the chat room. */
int chc_room_send(
        struct chc_room *room, 
        struct chc_room *user,
        struct chc_buffer *buffer,
        const size_t msgcount);







