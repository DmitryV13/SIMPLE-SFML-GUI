#pragma once
#include "BasicImage.h"

using namespace::sf;


/**
 * Представляет собой анимированную картинку.
 */
class AnimatedImage : public BasicImage{
private:
	IntRect current_frame;
	short frames_number;
	Clock animation_timer;
public:
    /**

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	AnimatedImage(TextureManager* t_manager, Warehouse* w_object, string name);

    /**

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param width ширина, под которую подстроится текстура.
        @param height высота, под которую подстроится текстура.
    */
	AnimatedImage(float width, float height, TextureManager* t_manager, Warehouse* w_object, string name);

    /**

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param first_frame координаты и размеры части текстуры, которая будет отображаться первой.
        @param frames_number_ количество кадров в данной текстуре.
    */
	AnimatedImage(TextureManager* t_manager, int index, string name, IntRect first_frame, short frames_number_);

    /**

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param first_frame координаты и размеры части текстуры, которая будет отображаться первой.
        @param frames_number_ количество кадров в данной текстуре.
        @param width ширина, под которую подстроится текстура.
        @param height высота, под которую подстроится текстура.
    */
	AnimatedImage(float width, float height, TextureManager* t_manager, int index, string name, IntRect first_frame, short frames_number_);
	~AnimatedImage();

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render();
};

