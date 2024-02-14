/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "tree/TerminalNode.h"

namespace antlr4 {
namespace tree {

  class ANTLR4CPP_PUBLIC TerminalNodeImpl : public TerminalNode {
  public:
    Token *symbol;

    explicit TerminalNodeImpl(Token *symbol) : TerminalNode(ParseTreeType::TERMINAL), symbol(symbol) {}

    virtual Token* getSymbol() const override;
    virtual void setParent(RuleContext *parent) override;
    virtual misc::Interval getSourceInterval() override;

    virtual std::any accept(ParseTreeVisitor *visitor) override;

    virtual std::string getText() override;
    virtual std::string toStringTree(Parser *parser, bool pretty = false) override;
    virtual std::string toString() override;
    virtual std::string toStringTree(bool pretty = false) override;

    inline bool operator== (const TerminalNode &other) const {
      std::cout << "TerminalNodeImpl operator== called" << std::endl;
      return getSymbol()->getText() == other.getSymbol()->getText() && getSymbol()->getType() == other.getSymbol()->getType();
    }

    inline bool equals(const TerminalNode* other) const {
      return getSymbol()->getText() == other->getSymbol()->getText() && getSymbol()->getType() == other->getSymbol()->getType();
    }
  };

} // namespace tree
} // namespace antlr4
