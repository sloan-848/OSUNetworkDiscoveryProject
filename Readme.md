## OSU Network Discovery Project

### What is this?
I decided to try scanning the entire IP block owned by Ohio State on ports 23, 80, and 443 for devices listening for telnet and HTTP connections. I used nmap for this task, and the scanning process took about an hour for both scans. I then manually went through the list of telnet connections and investigated those that seemed interesting. My notes can be found in the **interesting_ips.md** file. I then wrote a parsing program in C to pull the IP addresses from the nmap output in order to programmatically search all of the available HTTP machines. Using this list, I used PhantomJS and a ZSH script to automate the rendering of each page, and then saving a rasterized version to disk in order to be evaluated quickly.

I hope that this project encourages people to be careful in how they connect devices online, and I hope it is educational for some to see the work I have done.
