#pragma once
#include "AnimatedImage.h"
#include "InterfaceItem.h"
#include "INTERFACE_ITEM_TYPE.h"

using namespace::sf;

/**
 * Представляет галерею картинок.
 */
class Reviewer : public InterfaceItem{
private:
	short current_image;
	vector<BasicImage*> images;
	float scale;
	float max_width;
	float max_height;
	Vector2f position;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
    */
	Reviewer(float x, float y, float width_, float height_);
	~Reviewer();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Добавление в галлерею анимированной картинки.

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param first_frame координаты и размеры части текстуры, которая будет отображаться первой.
        @param frames_number_ количество кадров в данной текстуре.
    */
	void addAnimatedImage(TextureManager* t_manager, int index, string name, IntRect first_frame, short frames_number_);

    /** Добавление в галлерею анимированной картинки.

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	void addAnimatedImage(TextureManager* t_manager, Warehouse* w_object, string name);

    /** Добавление в галлерею неанимированной картинки.

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param first_frame координаты и размеры части текстуры, которая будет отображаться первой.
    */
	void addStaticImage(TextureManager* t_manager, int index, string name, IntRect first_frame);

    /** Добавление в галлерею неанимированной картинки.

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	void addStaticImage(TextureManager* t_manager, Warehouse* w_object, string name);

    /** Устанавливает новую позицию.

       @param position_ координаты новой позиции.
    */
	void setPosition(Vector2f position_);

    /** Устанавливает новую координату x для группы. Провоцирует изменение положения всех элементов группы.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для группы. Провоцирует изменение положения всех элементов группы.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Сдвигает группу и ее элементы на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Изменяет картинку, которая отображается в данный момент.

       @param next отвечает за то, какая картинка после текущей по счету будет отображаться.
       @param param2 параметр заглушка (не используется).
    */
	void changeCurrentImage(float next, float param2);

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

