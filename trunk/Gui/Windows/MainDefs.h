/**
 * Application: AbstractGraph
 * Module: GUI
 * File: MainDefs.h
 * Description: Main Application window definitions
 *
 * @author Dennis J. McWherter, Jr.
 * @version $Id$
 */

#ifndef WINDOWS_MAINDEFS_H__
#define WINDOWS_MAINDEFS_H__

// NOTE: To use this file, make sure <QString> is
// included _BEFORE_ this is included

// Menus
#define MAINWINDOW_FILE_MENU tr("&File")
#define MAINWINDOW_EDIT_MENU tr("&Edit")
#define MAINWINDOW_MODES_MENU tr("&Modes")
#define MAINWINDOW_ALG_MENU  tr("&Algorithms")

// File Menu Actions
#define MAINWINDOW_FILE_IMPORT tr("I&mport")
#define MAINWINDOW_FILE_EXPORT tr("E&xport")
#define MAINWINDOW_FILE_NEW tr("N&ew Tab")
#define MAINWINDOW_FILE_CLOSETAB tr("C&lose Current Tab")
#define MAINWINDOW_FILE_CLOSE tr("C&lose")

// Edit Menu Actions
#define MAINWINDOW_EDIT_REMOVENODE tr("R&emove Node")
#define MAINWINDOW_EDIT_ADDEDGE tr("A&dd Edge")

// Modes Menu Actions
#define MAINWINDOW_MODES_NODECREATION tr("N&ode Creation")
#define MAINWINDOW_MODES_EDGECREATION tr("E&dge Creation")
#define MAINWINDOW_MODES_VIEWONLY tr("V&iew Only")

// Algorithm Menu Actions
#define MAINWINDOW_ALG_SHORTEST tr("S&hortest Path")
#define MAINWINDOW_ALG_MST tr("M&inimum Spanning Tree")
#define MAINWINDOW_ALG_MAXMATCH tr("M&aximum Matching")
#define MAINWINDOW_ALG_MINVTXCOV tr("M&inimum Vertex Cover")
#define MAINWINDOW_ALG_MAXNET tr("M&aximum Network Flow")
#define MAINWINDOW_ALG_MINXY tr("M&inimum X-Y Cut")
#define MAINWINDOW_ALG_CHROMNO tr("Chromatic Number")
#define MAINWINDOW_ALG_PARTITE tr("Partite Sets")
#define MAINWINDOW_ALG_CYCLES tr("O&dd Cycle Detection")
#define MAINWINDOW_ALG_EULER tr("E&uler Paths/Circuits")
#define MAINWINDOW_ALG_CENTER tr("Center of Graph")
#define MAINWINDOW_ALG_PRUFER tr("Prufer Code (Trees)")
#define MAINWINDOW_ALG_DEBRUIJN tr("de Bruijn Cycles")

// IDs for hashing (only for ones which need it)
// File gets 0x1000 block
#define MAINWINDOW_FILE_EXPORT_ID 0x1001
#define MAINWINDOW_FILE_CLOSETAB_ID 0x1002

// Modes menu gets 0x2000 block
#define MAINWINDOW_MODES_NODE_ID 0x2001
#define MAINWINDOW_MODES_EDGE_ID 0x2002

#endif /* WINDOWS_MAINDEFS_H__ */