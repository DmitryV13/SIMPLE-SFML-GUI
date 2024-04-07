#pragma once
#include "INTERFACE_ITEM_TYPE.h"
#include "InterfaceItem.h"
#include "Group.h"
#include "Button.h"

using namespace::sf;

/** Элемент интерфейса - многовкладочная группа (в любой момент времени отображается только одна группа).
 */
class TabContainer: public InterfaceItem{
private:
	short current_tab;
	vector<Group*> tabs;

	float width;
	float height;
	Vector2f position;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
    */
	TabContainer(float x, float y, float width_, float height_);
	~TabContainer();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Устанавливает новую позицию неанимированной картинке.

       @param x координата.
       @param y координата.
    */
	void setPosition(float x, float y);

    /** Устанавливает новую координату x для группы. Провоцирует изменение положения всех элементов группы.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для группы. Провоцирует изменение положения всех элементов группы.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Добавление новой группы. Все добавляемые группы должны быть размерами аналогичными данному элементу

        @param tab новая группа
    */
	void addTab(Group* tab);

    /** Сдвигает группу и ее элементы на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Меняет группу, которая будет отображаться.

       @param tab_index индекс новой группы для отображения.
       @param param2 параметр заглушка (не используется).
    */
	void changeCurrentTab(float tab_index, float param2);

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

