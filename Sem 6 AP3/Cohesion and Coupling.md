### COHESION :
## The inter-related-ness of the elements of a Module in Design System;

# F S C P T -  Fir School Chale P T M ke liye
  HIGH  (1) Functional Cohesion : AuthServer[login(),logout(),resetPass()].
   |    (2) Sequential Cohesion : Template example[pour(),stir(),serve(), templateFunc(){pour() -> stir() -> serve()}Order of Function call is preserved].
   |    (3) Communicational Cohesion : Working on a common dataset/data structure Buffer Read Write Problem Example.
   |    (4) Procedural Cohesion : Part of a common workflow[Implementation of common Data Structures].
  LOW   (5) Temporal Cohesion : Related through concept of Time[Routine Class[WakeUp() -> haveBreakfast() -> haveLunch() -> haveDinner() -> Sleep()]].

For a good system design we need Low Coupling and High Cohesion.