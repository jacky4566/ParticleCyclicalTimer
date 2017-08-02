# ParticleCyclicalTimer
Simple use ON- OFF style timer for Particle Photon and Electron

# Disclaimer
Library still a work in progess, Feeback appreciated :)

# Methods
//Create an instance of cycleTimer with the following times

cycleTimer(byte ONhour, byte ONmin, byte OFFhour, byte OFFmin);

	
//Returns true if this timer is active

boolean isActive();

	
//Set on time for this timer

void setOnTime (byte hour, byte min);

	
//Set off time for this timer

void setOffTime (byte hour, byte min);
