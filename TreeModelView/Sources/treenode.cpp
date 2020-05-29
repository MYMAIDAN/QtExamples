#include "treenode.h"

TreeNode::TreeNode( const QVector<QVariant>& data, TreeNode* parent ) :
  mNodeData( data ),
  mParentNode( parent )
{

}

TreeNode::~TreeNode()
{
  qDeleteAll( mChildNodes );
}

TreeNode* TreeNode::parent() const
{
  return mParentNode;
}

TreeNode* TreeNode::child( uint32_t index )
{
  if( index < 0 || index >= static_cast<uint32_t>( mChildNodes.size() ) )
  {
    return nullptr;
  }
  return mChildNodes.at( index );
}

uint32_t TreeNode::childCount() const
{
  return static_cast<uint32_t>( mChildNodes.count() );
}

QVariant TreeNode::data( uint32_t column ) const
{
  if( column >= static_cast<uint32_t>( mNodeData.size() ) )
  {
    return QVariant();
  }
  return mNodeData.at( column );
}

bool TreeNode::setData( uint32_t column, const QVariant &value )
{
  if( column >= static_cast<uint32_t>( mNodeData.size() ) )
  {
    return false;
  }
  mNodeData[column] = value;
  return true;
}

bool TreeNode::insertChildren(uint32_t position, uint32_t count, uint32_t columns)
{

}




