#ifndef HOME_THEATER_FACADE_H
#define HOME_THEATER_FACADE_H

#include "devices.h"

class HomeTheaterFacade {
public:
    HomeTheaterFacade(Amplifier* amp,
            Tuner* tuner,
            StreamingPlayer* player, 
            Projector* projector, 
            Screen* screen,
            TheaterLights* lights,
            PopcornPopper* popper)
        : amp(amp), tuner(tuner), player(player), projector(projector),
            screen(screen), lights(lights), popper(popper) {}

    void watchMovie(std::string movie)
    {
        std::cout << "Get ready to watch a movie..." << std::endl;
        popper->on();
		popper->pop();
		lights->dim(10);
		screen->down();
		projector->on();
		projector->wideScreenMode();
		amp->on();
		amp->setStreamingPlayer(player);
		amp->setSurroundSound();
		amp->setVolume(5);
		player->on();
		player->play(movie);
    }

    void endMovie()
    {
        std::cout << "Shutting movie theater down..." << std::endl;
        popper->off();
		lights->on();
		screen->up();
		projector->off();
		amp->off();
		player->stop();
		player->off();
    }

    void listenToRadio(double frequency)
    {
        std::cout << "Tuning in the airwaves..." << std::endl;
        tuner->on();
		tuner->setFrequency(frequency);
		amp->on();
		amp->setVolume(5);
		amp->setTuner(tuner);
    }

    void endRadio()
    {
        std::cout << "Shutting down the tuner..." << std::endl;
        tuner->off();
        amp->off();
    }
    
private:
    Amplifier* amp;
	Tuner* tuner;
	StreamingPlayer* player;
	CdPlayer* cd;
	Projector* projector;
	TheaterLights* lights;
	Screen* screen;
	PopcornPopper* popper;
};

#endif // HOME_THEATER_FACADE_H