
#include "treemodel.h"

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QFile>
#include <QDirIterator>
#include <QDir>

void parseDir(QString dir, QModelIndex& parent, TreeModel& model)
{
  QDir qwe(dir);
  qwe.setFilter(  QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
  qwe.setSorting(QDir::Size | QDir::Reversed);
  auto list2 = qwe.entryInfoList();
  int j = 0;

  for( auto it: list2 )
  {
    if( it.isDir() )
    {
        model.insertRows(j,1,parent);
        model.setData(model.index(j,0,parent),it.fileName());
        auto par = model.index(j++,0,parent);
        parseDir( it.absoluteFilePath(),par,model);
    }
    if( it.isFile() )
    {
        model.insertRows(j,1,parent);
        model.setData(model.index(j++,0,parent),it.fileName());
    }
  }
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QWidget win;
  QHBoxLayout la;
  QTreeView v;
  const QStringList headers({("Title"), ("Description")});

  QFile file("E:\\projects\\QtExamples\\TreeModelView\\default.txt");
  file.open(QIODevice::ReadOnly);
  TreeModel *model = new TreeModel(headers, file.readAll());
  QDir ite("E:\\projects\\QtExamples\\TreeModelView\\");
  ite.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);
  ite.setSorting(QDir::Size | QDir::Reversed);
  auto list = ite.entryInfoList();
  model->insertRows( model->rowCount(), 1, model->index(model->rowCount(),0) );
  model->setData(model->index(model->rowCount()-1,0),ite.path());
  //model->insertColumn(0,model->index(model->rowCount()-1,0));
  auto parent = model->index(model->rowCount()-1,0);
      parseDir("C:\\Users\\Mishs\\Downloads\\VA - Heavy Metal Collections Vol. 16 (3CD +1CD LIVE) - 2020, FLAC", parent, *model);

  file.close();
  v.setModel(model);
  la.addWidget(&v);
  win.setLayout(&la);

  win.show();
  return a.exec();
}
