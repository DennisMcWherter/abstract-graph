/**
 * Application: AbstractGraph
 * Module: GUI
 * File: GLWindow.cpp
 * Description: Implementation for OpenGL window
 *
 * @author Dennis J. McWherter, Jr.
 * @version $Id$
 */

#include <string>
#include <utility>
#include <vector>

#include <QtGui/QColorDialog>
#include <QtGui/QInputDialog>
#include <QtGui/QMouseEvent>

#include "GLWindow.h"

#include "../Menus/NodeOptionsMenu.h"
#include "../Menus/MenuDefs.h"

#include "graphix.h"

GLWindow::GLWindow(QWidget* parent)
  : QGLWidget(parent), nodeRightClick(new NodeOptionsMenu(this))
{
}

GLWindow::~GLWindow()
{
}

void GLWindow::updateMode(GRAPHIX::MODES mode)
{
  scene.updateMode(mode);
  updateGL();
}

void GLWindow::initalizeGL()
{
  makeCurrent();
}

void GLWindow::resizeGL(int w, int h)
{
  scene.updateGLSize(w, h);
}

void GLWindow::paintGL()
{
  scene.updateScene();
  drawLabels();
}

void GLWindow::mousePressEvent(QMouseEvent* evt)
{
  Qt::MouseButton button = evt->button();
  
  // Make sure are coordinates are from the proper perspective
  QPoint pos(evt->pos());
  mapFromGlobal(pos);
  int x = pos.x();
  int y = pos.y();
  
  if(button == Qt::LeftButton) {
    scene.registerClick(x, y);
    updateGL();
  }
}

void GLWindow::mouseMoveEvent(QMouseEvent* evt)
{
  // Not implemented
}

void GLWindow::keyPressEvent(QKeyEvent* evt)
{
  // Not implemented
}

void GLWindow::contextMenuEvent(QContextMenuEvent* evt)
{
  if(evt == NULL)
    return;
  
  QPoint pos(evt->globalPos());
  nodeRightClick->updateMenuItems(scene.checkNodesSelected(), scene.countSelected());
  nodeRightClick->exec(pos);
}

void GLWindow::deleteSelected()
{
  scene.deleteSelected();
  updateGL();
}

void GLWindow::updateColor()
{
  QColor color = Qt::white;
  bool isValid = showColorDialog(color);

  if(isValid) {
    int red = 0;
    int green = 0;
    int blue = 0;
    color.getRgb(&red, &green, &blue);
    
    scene.updateSelectedColor(red, green, blue);
    
    updateGL();
  }
}

void GLWindow::updateHighlight()
{
  QColor color = Qt::white;
  bool isValid = showColorDialog(color);
  
  if(isValid) {
    int red = 0;
    int green = 0;
    int blue = 0;
    color.getRgb(&red, &green, &blue);

    scene.updateHighlightColor(red, green, blue);

    updateGL();
  }
}

void GLWindow::updateBackground()
{
  QColor color = Qt::white;
  bool isValid = showColorDialog(color);
  
  if(isValid) {
    int red = 0;
    int green = 0;
    int blue = 0;
    color.getRgb(&red, &green, &blue);
    
    scene.updateBackground(red, green, blue);
    
    updateGL();
  }
}

void GLWindow::updateLabel()
{
  bool ok;
  QString label;
  std::vector<std::string> labels = scene.getSelectedLabels();
  QString existingLabel(labels[0].c_str());

  if(labels.size() == 1)
    label = QInputDialog::getText(this, tr("Add/Edit Label"), tr("Update Label:"),  QLineEdit::Normal, existingLabel, &ok);
  else
    label = QInputDialog::getText(this, tr("Add/Edit Label"), tr("Update Label:"),  QLineEdit::Normal, tr(""), &ok);
  
  if(ok) {
    scene.updateLabel(label.toStdString());
    updateGL();
  }
}

void GLWindow::selectAll()
{
  scene.selectAll();
  updateGL();
}

void GLWindow::deselectAll()
{
  scene.deselectAll();
  updateGL();
}

void GLWindow::drawLabels()
{
  std::vector<std::string> labels = scene.getLabels();
  std::vector<std::pair<int, int> > coords = scene.getCoords();
  
  if(labels.size() != coords.size())
    return;
  
  for(unsigned i = 0 ; i < labels.size() ; ++i) {
    if(labels[i].empty())
      continue;
    renderText(coords[i].first, coords[i].second, QString(labels[i].c_str()));
  }
}

bool GLWindow::showColorDialog(QColor& color)
{
  color = QColorDialog::getColor(color, this, tr("Select Color"));
  return color.isValid();
}