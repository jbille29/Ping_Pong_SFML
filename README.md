# Ping_Pong_SFML
Simple game of ping pong

Below is a screen-shot of the ping pong game. This game was developed using C++ and SFML. It features a scoring system and frame-rate independent movement of a bat and a ball. The bat is controlled by the player and can go side to side. While the ball falls to the bottom of the screen. The purpose of the game is to rebound the ball of the bat and not let it pass by to the bottom of the screen. If the ball touches the top of the screen a point is awarded, but if it touches the bottom a life is taken away from the player.

The game loop has variable time steps for now although this will be changed to minimum time steps in the future. There is currently a problem with the collision between the bat and ball. This is probably attributed to the fact it is a variable time loop and the collision functionality is being called faster than the bat and ball are updated. So this problem should go away with the implementation of a minimum time step loop. If not, I plan to add a Collider class that will replace the current collision functionality in the future.

![image](https://user-images.githubusercontent.com/29133645/46113416-e4660c80-c1b3-11e8-971e-1bb0167cc50a.png)
