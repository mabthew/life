#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QColor>

#include "cell.h"
#include <string>

QColor Cell::alive_color_ = QColor(255,20,147);
QColor Cell::dead_color_ = QColor(255, 255, 255);


/**
  Creates a new Cell object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/
/**
    Cell constructor
    @param x, @param y, @param color, @param alive = initial cell attributes
    @return void
*/
Cell::Cell(QColor color, const int x, const int y, bool alive) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  alive_ = alive;
}
/**
    flips the vivality of the cell
    @return void
*/
void Cell::now_this_is_the_story_all_about_how_my_life_got_flipped_turned_upside_down(){
    alive_ = !alive_;
}
/**
    basic func to create rect of ell
    @return void
*/
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}
/**
    basic func to add ellipse for cell
    @return void
*/
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

/**
    Basic setup of ui for cell
    @return void
*/
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}


/**
    signal to signify that the cell was clicked
    @return void
*/
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // update this QGraphicsItem (force it to re-draw)
    //update();
    emit CellSelected(this);
}




/**
  Makes it so the == operator will have the behavior that you
  expect when comparing cells.
  You can overload pretty much any operator in c++
  @param first Point left hand side of the expression
  @param other Point right hand side of the expression
*/
bool operator==(const Cell &first, const Cell &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}
