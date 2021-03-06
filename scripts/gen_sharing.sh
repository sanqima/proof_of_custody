#!/usr/bin/expect

# FIRST: sudo apt install expect

# p
if {$argc < 1} {
   send_user "usage: $argv0 <t>\n"
   exit
}

# <t> the number of threshold, and 0 < t < n/2.
set t [lindex $argv 0]
set timeout 60

spawn ./Setup.x
expect "Enter a number"
send "2\n"
expect "Enter2 a number"
send "2\n"
expect "for secret sharing"
send "4002409555221667393417789825735904156556882819939007885332058136124031650490837864442687629129015664037894272559787\n"
expect "Enter threshold"
send "${t}\n"
expect off
