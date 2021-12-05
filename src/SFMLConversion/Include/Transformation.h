//
// Created by ferit on 15/12/2020.
//

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H

    class Transformation {
    private:
        /* Stored instance*/
        static Transformation *instance;

        /*Private constructor*/
        Transformation();

    public:
        /*Static acces method */
        static Transformation *getInstance();

        /*Delete copy constructor*/
        Transformation(const Transformation &obj) = delete;

        /*Delete copy assignment*/
        Transformation &operator=(const Transformation &) = delete;

        int x;

    };


#endif //GAME_TRANSFORMATION_H
