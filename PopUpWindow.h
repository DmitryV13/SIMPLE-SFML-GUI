#pragma once
#include "Button.h"
#include "Reviewer.h"
#include "ComposedIMG.h"
#include "Label.h"
#include "Group.h"
#include "BUTTON_STATE.h"
#include "POP_UP_WINDOW_STATE.h"
#include "CallbacksHandler.h"
#include "DCallbacksHandler.h"

/**
 * Представляет собой базовое всплывающее окно
 */
class PopUpWindow{
protected:
	TextureManager* manager;
	ComposedIMG* w_background;
	RectangleShape* background;
	Label* label;
	short puw_state;

	CallbacksHandler* callbacks_handler;
	DCallbacksHandler* dcallbacks_handler;
	//inner clean parameters
	int width;
	int height;

	Vector2f position;

	vector<vector<Group*>> groups;
public:
    /**
       @param screen_width ширина экрана.
       @param screen_height высота экрана.
       @param width_ ширина всплывающего окна.
       @param height_ высота всплывающего окна.
       @param t_manager_ менеджер текстур, из которого берется текстура заднего фона всплывающего окна.
       @note при дальнейшей разработке, возможно, данный параметр будет удален из конструктора.
    */
	PopUpWindow(double screen_width, double screen_height, int width_, int height_, 
		TextureManager* t_manager_);

    /** Не используется на данный момент.
    */
	PopUpWindow(double screen_width, double screen_height, int width_, int height_, 
		string positionX, string positionY, TextureManager* t_manager_);

    /** Не используется на данный момент.
    */
	PopUpWindow(double screen_width, double screen_height, int width_, int height_, 
		string positionX, int y, TextureManager* t_manager_);

    /** Не используется на данный момент.
    */
	PopUpWindow(double screen_width, double screen_height, int width_, int height_, 
		int x, string positionY, TextureManager* t_manager_);
	~PopUpWindow();

    /** Не обладает реализацией на данный момент.
    */
	void setBackground();

    /** Не обладает реализацией на данный момент.
    */
	void setSize();

    /** Задает состояние текущего окна(POP_UP_WINDOW_STATE).

        @param param1 хранит значение нового состояния. В методе происходит static_cast<short> этого параметра.
        @param param2 заглушка.
    */
	void setPUWState(float param1, float param2);

    /** Возвращает состояние текущего окна(POP_UP_WINDOW_STATE).
    */
	short getState();

    /** Системный метод.
    */
	int getMaxGroupsHeight(short index);

    /** Создает новую строку в окне для последующего добавления в нее групп.
        Вызов данной функции обязателен перед добавлением группы в новую строку окна.
     */
	void createGroupLine();

    /** Добавляет ярлык для всплывающего окна. Ярлык будет отображаться над всплывающим окном по центру.

       @param screen_width ширина экрана.
       @param screen_height высота экрана.
       @param label_text текст ярлыка.
       @param text_size размер шрифта.
       @param offset зазор между ярлыком и всплывающим окном.
    */
	void addLabel(double screen_width, double screen_height, const string& label_text, int text_size, short offset);

    /** Добавляет группу в окно. Добавление произойдет в конец указанной строки.

       @param fill_p_w процент заполнения(указывается от 0 до 100), по которому установится ширина новой группы
        на основе текущего окна.
       @param fill_p_h процент заполнения(указывается от 0 до 100), по которому установится высота новой группы
        на основе текущего окна.
       @param index индекс строки куда произойдет добавление.
       @param name заголовок группы.
       @param name_size размер шрифта.
    */
    void addGroup(short fill_p_w, short fill_p_h, short index, string name, int name_size);// fill percentage width/height

    /** Добавляет группу в окно. Добавление произойдет в конец указанной строки.

       @param fill_p_w процент заполнения(указывается от 0 до 100), по которому установится ширина новой группы
        на основе текущего окна.
       @param fill_p_h процент заполнения(указывается от 0 до 100), по которому установится высота новой группы
        на основе текущего окна.
       @param index индекс строки куда произойдет добавление.
    */
    void addGroup(short fill_p_w, short fill_p_h, short index);

    /** Добавляет группу в окно. Добавление произойдет в конец указанной строки.

       @param new_group новая группа.
       @param index индекс строки куда произойдет добавление.
    */
	void addGroup(Group* new_group, short index);

    /** Добавляет имя группе, расположенной по заданным индексам.

       @param i индекс строки.
       @param j индекс столбца.
       @param name заголовок группы.
       @param name_size размер шрифта.
    */
	void addGroupName(int i, int j, string name, int name_size);

    /** Задает цвет заднего фона, который отображается пока окно открыто. По умолчанию цвет заднего фона
       прозрачный. Используется только первый раз при задании фона.

       @param map_width ширина экрана.
       @param map_height высота экрана.
       @param color новый цвет.
    */
	void addBackground(double map_width, double map_height, Color color);

    /** Не обладает реализацией на данный момент.
    */
	void addDelimiter();

    /** Добавляет статический отклик на событие, выявление и выполнение которого будет происходить при
       обновлении окна. Сигнатуру передаваемой функции смотреть в описании клсса CallbacksHandler.

       @param b_state состояние, которое будет считываться и которое спровоцирует отклик.
       @param a_state значение активного состояния.
       @param param1 первый статический параметр функции отклика.
       @param param2 второй статический параметр функции отклика.
       @param l_func функция отклика, задается в виде &Class::function.
       @param l_instance указатель на обьект класса.
       @return булевое значение, указывающее на то, был ли добавлен отклик.
    */
	template<class T>
	bool addCallback(short* b_state, short a_state, float param1, float param2, void(T::* l_func)(float, float), T* l_instance);

    /** Добавляет динамический отклик на событие, выявление и выполнение которого будет происходить при
       обновлении окна. Сигнатуру передаваемой функции смотреть в описании клсса DCallbacksHandler.

       @param b_state состояние, которое будет считываться и которое спровоцирует отклик.
       @param a_state значение активного состояния.
       @param param1 первый динамический параметр функции отклика.
       @param param2 второй динамический параметр функции отклика.
       @param l_func функция отклика, задается в виде &Class::function.
       @param l_instance указатель на обьект класса.
       @return булевое значение, указывающее на то, был ли добавлен отклик.
    */
	template<class T>
	bool addDCallback(short* b_state, short a_state, string* param1, string* param2, void(T::* l_func)(string*, string*), T* l_instance);

    /** Расчитывает размеры и позицию для новой группы. Позиция считается со следующей группы
        указанной строки.

        @param fill_p_w процент заполнения(указывается от 0 до 100) ширины для новой
        группы на основе текущей группы.
        @param fill_p_h процент заполнения(указывается от 0 до 100) высоты для новой
        группы на основе текущей группы.
        @param index индекс строки.
        @return возвращает CRect<float> с посчитанными параметрами.
    */
	CRect<float>* calculatePFNG(short fill_p_w, short fill_p_h, short index);//parameters for new group

    /** Системный метод.
    */
	void formInput(Event event);

    /** Системный метод.
    */
	void itemScroll(float delta);

    /** Обновляет окно и все элементы, которые ему принадлежат.
    */
	virtual void update();

    /** Обновляет окно и все элементы, которые ему принадлежат, в зависимости от принимаемого события события.

        @param event событие.
    */
	void updateEvent(Event* event);

    /** Отображает окно и все элементы, которые ему принадлежат.
    */
	virtual void render();
};

template<class T>
inline bool PopUpWindow::addCallback(short* b_state, short a_state, float param1, float param2, void(T::* l_func)(float, float), T* l_instance){
	return callbacks_handler->addCallback(b_state, a_state, param1, param2, l_func, l_instance);
}

template<class T>
inline bool PopUpWindow::addDCallback(short* b_state, short a_state, string* param1, string* param2, void(T::* l_func)(string*, string*), T* l_instance) {
	return dcallbacks_handler->addCallback(b_state, a_state, param1, param2, l_func, l_instance);
}
