
world access:

    permission create instance "basic" : user[admin]
    
    permission set user flag "admin" : user[staff] and user[lead].

<ROOM>
name: basic.
default admin: staff, lead.
default guest: guest.
privilege TYPE: FLAGS.

<MOD>
name: basic.
timeout: 30 minutes..
warnings: 2 every 1 months.
privilege: user[staff] | user[lead].
<DESC>
Bad language.
</DESC>
</MOD>

</ROOM>


