#pragma once
#include "InterfaceItem.h"
#include "ImageButton.h"
#include "FormItem.h"
#include "InputField.h"
#include "TextareaField.h"
#include "NumberField.h"

/**
 * Базовый класс для группировки элементов.
 */
class Group : public InterfaceItem{
protected:
	//Objects for visualization
	RectangleShape shape0;
	RectangleShape shape1;
	RectangleShape shape2;

	RectangleShape background;
	Text* name;
	vector<vector<InterfaceItem*>> g_elements;

	float inner_width;
	float inner_height;
	float outer_width;
	float outer_height;
	Vector2f position;
public:
    /**

        @param x координата.
        @param y координата.
        @param width_ ширина.
        @param height_ высота.
    */
	Group(float x, float y, float width_, float height_);
	~Group();

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Системный метод.
    */
	std::pair<float, float> getMaxELHeight(short index);

    /** Возвращает указатель на состояние кнопки по ее идентификатору.

       @param btn_id идентификатор кнопки, чьё состояние нам необходимо получить.
    */
	short* getButtonState(int btn_id);

    /** Устанавливает горизонтальное и вертикальное выравнивание элементов 1 уровня в группе.

       @param horiz_a горизонтальное выравнивание.
       @param vertic_a вертикальное выравнивание.
       @note строковые переменные выравнивания состоят из трех частей разделенных пробелами("1 2 3").
       @note параметр 1 - тип выравнивания(left, right, top, bottom, center, space around, space between),
       присутствие обязательно.
       @note параметр 2 - начальный отступ(z - без начального отступа, "" - начальный отступ выбирается
       автоматически), присутствие необязательно. Для выравнивания типа
       space around, space between и center неприменим.
       @note параметр 3 - расстояние между элементами(число, auto), при auto расстояние между элементами,
       а также начальный отступ выбиратеся как половина ширины/высоты первого элемента. Присутствие обязательно
       для всех типов выравнивания кроме space around.
    */
	void setAlignment(string horiz_a, string vertic_a);

    /** Устанавливает вертикальное выравнивание элементов 1 уровня в группе.

       @param vertic_a вертикальное выравнивание.
    */
	void setVAlignment(string vertic_a);

    /** Устанавливает горизонтальное выравнивание элементов 1 уровня в группе.

       @param horiz_a горизонтальное выравнивание.
    */
	void setHAlignment(string horiz_a);

    /** Устанавливает новую координату x для группы. Провоцирует изменение положения всех элементов группы.

       @param x новая координата x.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y для группы. Провоцирует изменение положения всех элементов группы.

       @param y новая координата y.
    */
	void setPositionY(float y) override;

    /** Устанавливает цвет заливки заднего фона группы. По умолчанию цвет фона прозрачный.

        @param color новый цвет фона.
    */
	void setBColor(Color color);

    /** Системный метод.
    */
	void normalization();

    /** Системный метод.
    */
	void changeChildrenPosition(float offset_x, float offset_y) override;

    /** Сдвигает группу и ее элементы на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Сдвигает группу и ее элементы на заданное смещение по оси y.

       @param offset смещение по y.
    */
	void changePositionY(float offset);

    /** Создает новую строку в группе для последующего добавления в нее элементов.
        Вызов данной функции обязателен перед добавлением элемента интерфейса в новую строку группы.
     */
	void createElementLine();

    /** Удаляет все содержимое группы. Если до очищения в группе была хоть одна строка с элементами, то после
        очищения, перед добавлением нового элемента необходимо убедиться ,что строка с нужным индексом создана
        методом createElementLine().
     */
	void clearInfo();

    /** Добавляет элемент интерфейса в группу. Добавление произойдет в конец указанной строки.

        @param new_group новый элемент интерфейса.
        @param index индекс строки куда произойдет добавление.
    */
	void addIElement(InterfaceItem* new_group, short index);

    /** Создает новую группу(как элемент интерфейса) в текущей и добавляет в конец указанной строки.

        @param fill_p_w процент заполнения(указывается от 0 до 100), по которому установится ширина новой группы
        на основе текущей.
        @param fill_p_h процент заполнения(указывается от 0 до 100), по которому установится высота новой группы
        на основе текущей.
        @param index индекс строки куда произойдет добавление.
        /return возвращает идентификатор только что добавленной группы.
    */
	int addGroup(short fill_p_w, short fill_p_h, short index);

    /** Добавляет имя текущей группе. Используется до добавления в группу элементов интерфейса, так как влияет
        на ее дальнейшие размеры(уменьшается высота контентной зоны).

        @param text_name заголовок группы.
        @param name_size размер шрифта.
    */
	void addGroupName(string text_name, int name_size);

    /** Создает новую текстовую кнопку без контура(как элемент интерфейса) в текущей группе и добавляет в конец
        указанной строки. Размеры прямоугольной области установятся по размерам текста.

        @param text_size размер шрифта.
        @param btn_name текст кнопки.
        @param btn_color цвет текста при наведении на кнопку.
        @param index_g индекс строки куда произойдет добавление.
        @return возвращает идентификатор только что добавленной кнопки.
    */
	int addButton(short text_size, string btn_name, Color btn_color, short index_g);

    /** Создает новую текстовую кнопку(как элемент интерфейса) в текущей группе и добавляет в конец
        указанной строки.

        @param width ширина кнопки.
        @param height высота кнопки.
        @param text_size размер шрифта.
        @param btn_name текст кнопки.
        @param btn_hcolor цвет текста при наведении на кнопку.
        @param btn_icolor цвет текста в неработающем состоянии.
        @param shp_hcolor цвет прямоугольной области при наведении на кнопку.
        @param shp_icolor цвет прямоугольной области в неработающем состоянии.
        @param outline контур.
        @param index_g индекс строки куда произойдет добавление.
        @return возвращает идентификатор только что добавленной кнопки.
    */
	int addButton(float width, float height, short text_size
		, string btn_name, Color btn_hcolor, Color btn_icolor, Color shp_hcolor, Color shp_icolor
		, bool outline, short index_g);

    /** Создает новую анимированную кнопку(как элемент интерфейса) в текущей группе и добавляет в конец
        указанной строки.

        @param width ширина кнопки.
        @param height высота кнопки.
        @param text_size размер шрифта.
        @param btn_name текст кнопки.
        @param btn_hcolor цвет текста при наведении на кнопку.
        @param btn_icolor цвет текста в неработающем состоянии.
        @param shp_hcolor цвет прямоугольной области при наведении на кнопку.
        @param shp_icolor цвет прямоугольной области в неработающем состоянии.
        @param t_manager менеджер текстур.
        @param index_t индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param outline контур.
        @param index_g индекс строки куда произойдет добавление.
        @return возвращает идентификатор только что добавленной кнопки.
    */
	int addButton(float width, float height, short text_size, string btn_name
		, Color btn_hcolor, Color btn_icolor, Color shp_hcolor, Color shp_icolor
		, TextureManager* t_manager, int index_t, string name, bool outline, short index_g);
	//void addDelimiter();
	//void addSlider();

    /** Расчитывает размеры и позицию для нового элемента интерфейса. Позиция считается со следующего элемента
        указанной строки.

        @param fill_p_w процент заполнения(указывается от 0 до 100) ширины для нового
        элемента на основе текущей группы.
        @param fill_p_h процент заполнения(указывается от 0 до 100) высоты для нового
        элемента на основе текущей группы.
        @param index индекс строки.
        @return возвращает CRect<float> с посчитанными параметрами. В нем первый параметр - x,
        второй параметр -y, третий параметр - width, четвертый параметр - height.
    */
	CRect<float>* calculatePFNII(short fill_p_w, short fill_p_h, short index);

    /** Устанавливает состояния всех элементов, принадлежащих группе по умолчанию.
    */
	void resetActiveState() override;

    /** Системный метод.
    */
	bool itemScroll(float delta) override;

    /** Системный метод.
    */
	void formInput(Event event);

    /** Обновляет группу и все элементы, которые ей принадлежат.
    */
	void update() override;

    /** Отображает группу и все элементы, которые ей принадлежат.
    */
	void render();
};

