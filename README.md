# Attiny85 Motion Activated Tilt/Pan Laser Pointer Cat/Dog Toy

<b>Inspiration</b>
I have an active cat that loves to play in any sort of way. Sometimes though...you just feel a little lazy.

I had seen other guides for making laser pointers that are attached to servos that could tilt and pan, but none were quite what I was looking for. There was a lot of guides that showed you how to control a laser pointer/servo with a phone or IR remote. Some required you to take apart a normal laser pointer. Not many used motion detection. Blah! Time to make my own.

<iframe width="560" height="315" src="https://www.youtube.com/embed/gQPztTNuJ8g" frameborder="0" allowfullscreen></iframe>

<b>Goals:</b>
1. Use an arduino to control two servos
2. 3D printed parts to combine the servos together for tilt/pan action
3. Use a standard 6mm laser that can be found for very cheap on Amazon/Banggood/etc
4. Use a standard PIR sensor to turn it on/off if the cat is around

<b>Tools Needed:</b>
Depends on how you want to build it. Likely will need a soldering iron, wire cutters, screw drivers, all that good stuff. If you want to make 3D printed parts, obviously a 3D printer, but that is not necessary.

<b>Parts Needed:</b>
Note-I really like using Amazon Prime for electronics. Slightly higher prices, but cheaper than Adafruit/Sparkfun, with faster shipping. If shipping time doesn't matter and you want it for cheap, I always like to go with <a href="http://www.banggood.com">Banngood</a>.

1) Two Servos: <a href="https://www.amazon.com/TowerPro-SG90-Micro-Servo-2pk/dp/B01608II3Q/ref=sr_1_2?s=toys-and-games&ie=UTF8&qid=1492046990&sr=1-2&keywords=servo">SG90 Micro Servos</a>. You only need two, but its only like 4 more bucks to get 5. These aren't super high quality, so I'd grab some extras, also for future projects
2) 6mm Laser: I used these <a href="https://www.amazon.com/Greatwell-650nm-Laser-Module-Copper/dp/B01J7WFIOY/ref=sr_1_1?s=toys-and-games&ie=UTF8&qid=1492047083&sr=1-1&keywords=6mm+laser">ones</a>. Yep...you get 10 of them. Only need 1 though.
3) PIR Sensor: There are tons of places to get these around the net. <a href="https://www.amazon.com/EMY-HC-SR501-Pyroelectric-Infrared-Detector/dp/B00FDPO9B8/ref=sr_1_1?rps=1&ie=UTF8&qid=1492047279&sr=8-1&keywords=pir+sensor&refinements=p_85%3A2470955011">These ones</a> come out to like 2 bucks each.
4) Attiny85: Plenty of options here. I prefer using the Sparkfun <a href="https://www.sparkfun.com/products/11801">Tiny AVR Programmer</a> and just a <a href="https://www.amazon.com/ATMEL-ATTINY85-20PU-8-BIT-20MHz-MCU/dp/B00PT4XU04/ref=sr_1_3?rps=1&ie=UTF8&qid=1492047811&sr=8-3&keywords=attiny85&refinements=p_85%3A2470955011">plain ol' Attiny85</a>. You can use the ones with <a href="https://www.amazon.com/UEB-Digispark-Kickstarter-Attiny85-Development/dp/B01N59NDG0/ref=sr_1_1?rps=1&ie=UTF8&qid=1492048010&sr=8-1&keywords=attiny85&refinements=p_85%3A2470955011">built in usb to serial chips</a>, <a href="https://www.adafruit.com/product/1501">Adafruit Trinket</a>, whatever your heart desires as long as there is an Attiny85 on it.
5) Breadboard, jumper wire, and all that other good stuff.

<b><i>The following items are only needed if you want to build it onto a PCB and not use a breadboard</i></b>
6) 8-pin DIP Socket: <a href="https://www.sparkfun.com/products/11801">Here are some on Amazon</a>
7) PCB Board: Here is a <a href="https://www.amazon.com/Paxcoo-Double-Sided-Board-Prototype/dp/B01M7R5YIB/ref=sr_1_2?ie=UTF8&qid=1492048133&sr=8-2-spons&keywords=pcb&psc=1">link to some</a>, any will do. I always go with double sided. You'll see in the pics I cut a board down significantly to lower the footprint.</i></b>

<b>Powering the Circuit</b>

There are a few ways to do this...
1) Use a rechargeable lithium ion battery: This is the one I use from <a href="https://www.adafruit.com/product/1578">Adafruit</a> This will just require you to have a male JST connector to power the Attiny85
2) Use a cellphone power bank and splice an old USB cord to use with it (I love my USB cable that has two jumper cables spliced into it)
3) Normal batteries–The Attiny85 runs on 5v max. So make sure you don't plug a 9v straight into it. Here is a nice little article on <a href="http://electronics.stackexchange.com/questions/8112/how-do-i-convert-9-v-dc-to-5-v">how to get 9 volts down to 5 volts</a>.

<b>Materials to Put it All Together</b>

There are two key pieces needed to get the whole thing together:
1) Tilt/Pan Servo Mount: You can 3D print this if you want. Here is <a href="http://www.thingiverse.com/thing:708819">the design I used</a> from Thingiverse. On my most recent iteration though, I said screw it and just bought a <a href="https://www.amazon.com/Camera-Platform-Anti-Vibration-Mount-servo/dp/B00FHRVI5C/ref=pd_cp_147_4?_encoding=UTF8&pd_rd_i=B00FHRVI5C&pd_rd_r=33T20EFP0FE4W4HJW9MJ&pd_rd_w=rnJKE&pd_rd_wg=3U1Pi&psc=1&refRID=33T20EFP0FE4W4HJW9MJ">pre-made, injection molded one</a>.
2) PIR Sensor Mount: This is pretty easy if you have a 3D printer–one with <a href="http://www.thingiverse.com/search?q=pir+sensor&sa=">quick search on Thingiverse</a>. If you don't have a 3D printer, the PIR sensors do have mounting holes on them, but require pretty small screws (2/56 that you could attached to the enclosure of your choice.

After that, go wild and make it however you want. I've done three iterations basically. Below are a few of my different iterations of construction it...my final iteration is the security camera version. But you could use a cardboard box if you want...below are some pictures of my final products.

<b>Iteration #1</b>

Using a scaled down version of <a href="http://www.thingiverse.com/thing:607652">this design</a> along with the tilt/pan design linked about. Powering with a 9v battery and a 9v to 5v circuit. Cat liked knocking this over when not in use.
<img src="https://github.com/tonylandek/attiny85_cat_laser_pointer_machine/blob/master/kittylaser.JPG?raw=true"></img>

<b>Iteration #2</b>
Decided to make my own fully 3D printed structure. Original goal was to house all electronics within the PIR housing and the first tower. The second tower was to hold this particular <a href="http://www.microcenter.com/product/447266/2,600mAh_Power_Bank_Battery_Charger_for_Mobile_Devices_-_White">cheapo power bank</a> from Microcenter.
https://github.com/tonylandek/attiny85_cat_laser_pointer_machine/blob/master/3D%20Render.jpg
