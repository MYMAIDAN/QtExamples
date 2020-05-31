
#include "treemodel.h"

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QFile>
#include <QDirIterator>
#include <QDir>

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
  auto list = ite.entryInfoList();
  model->insertRows( model->rowCount(), 1, model->index(model->rowCount(),0) );
  model->setData(model->index(model->rowCount()-1,0),ite.path());
  //model->insertColumn(0,model->index(model->rowCount()-1,0));

  auto parent = model->index(model->rowCount()-1,0);
  int i = 0;
  for( auto it: list )
  {
    if( it.isDir() )
    {
        auto in = parent.column();
        model->insertRows(i,1,parent);
        model->setData(model->index(i,0,model->index(model->rowCount()-1,0)),it.fileName());
        QDir qwe(it.absoluteFilePath());
        auto list2 = qwe.entryInfoList();
        int j = 0;
        auto par = model->index(i++,0,model->index(model->rowCount()-1,0));
        for( auto it: list2 )
        {
          if( it.isDir() )
          {
              model->insertRows(j,1,par);
              model->setData(model->index(j++,0,par),it.fileName());

          }
          if( it.isFile() )
          {
              model->insertRows(j,1,par);
              model->setData(model->index(j++,0,par),it.fileName());
          }
        }

    }
    if( it.isFile() )
    {
        auto in = parent.column();
        model->insertRows(i,1,parent);
        model->setData(model->index(i++,0,model->index(model->rowCount()-1,0)),it.fileName());
    }
  }

  file.close();
  v.setModel(model);
  la.addWidget(&v);
  win.setLayout(&la);

  win.show();
  return a.exec();
}
