#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <QObject>
#include <QVariant>
#include <QVector>

class TreeNode
{
public:
  explicit TreeNode( const QVector<QVariant>& data, TreeNode* parent = nullptr );
  ~TreeNode();

  TreeNode* parent() const;
  TreeNode* child( uint32_t index );
  uint32_t  childCount() const;
  uint32_t  columnCount() const;
  QVariant  data( uint32_t  column ) const;
  bool      setData( uint32_t column, const QVariant& value );
  bool      insertChildren( uint32_t position, uint32_t count,  uint32_t columns );
  bool      insertColumns( uint32_t position, uint32_t count );
  bool      removeChildren( uint32_t position, uint32_t count );
  bool      removeColumns( uint32_t position, uint32_t columns );
  uint32_t  childNumber() const;


private:
  QVector<TreeNode*> mChildNodes;
  QVector<QVariant>  mNodeData;
  TreeNode*          mParentNode;
};

#endif // _TREENODE_H_
