# Pinball
Originally I started out with an idea that I want to use LeapMotion in my midterm, but perhaps I will leave that for final after we learn more useful tools. 
Moving on, I decided that I want to create pinball machine in OF, thanks to your, I was able to figure out and understand how to do collision detection. I draw the paddles using circles as you suggested, as well as some obstacles. For the ball to bounce back, I changed the direction of y-speed  of the ball by adding this line when it collided: `ball.speed.y *= -1;`

You start it off with three lives, and the interaction is using KeyPressed and KeyReleased of w/s and o/k to control the LEFT and RIGHT paddles. 


