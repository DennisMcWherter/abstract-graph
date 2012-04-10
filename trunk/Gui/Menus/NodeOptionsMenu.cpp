/**
 * Application: AbstractGraph
 * Module: GUI
 * File: NodeOptionsMenu.cpp
 * Description: Implementation for Node options menu
 *
 * @author Dennis J. McWherter, Jr.
 * @version $Id$
 */

#include "NodeOptionsMenu.h"
#include "MenuDefs.h"
#include "../Windows/GLWindow.h"

NodeOptionsMenu::NodeOptionsMenu(GLWindow* parent)
  : QMenu(parent)
{
  init();
}

NodeOptionsMenu::~NodeOptionsMenu()
{
}

void NodeOptionsMenu::updateMenuItems(bool selected, unsigned numSelected)
{
  label->setEnabled(numSelected == 1);
  del->setEnabled(selected);
}

void NodeOptionsMenu::init()
{
  label = new QAction(MENU_GENERAL_LABEL, this);
  del   = new QAction(MENU_GENERAL_DELETE, this);
  
  connect(label, SIGNAL(triggered()), parent(), SLOT(updateLabel()));
  connect(del, SIGNAL(triggered()), parent(), SLOT(deleteSelected()));
  
  this->addAction(label);
  this->addAction(del);
}