/*
 * Copyright (c) 2001, 2018, Oracle and/or its affiliates. All rights reserved.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

package jdk.javadoc.internal.doclets.toolkit.taglets;

import java.util.ArrayList;
import java.util.EnumSet;
import java.util.List;

import javax.lang.model.element.Element;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.type.TypeMirror;

import com.sun.source.doctree.DocTree;
import jdk.javadoc.internal.doclets.toolkit.Content;
import jdk.javadoc.internal.doclets.toolkit.Messages;
import jdk.javadoc.internal.doclets.toolkit.util.CommentHelper;
import jdk.javadoc.internal.doclets.toolkit.util.DocFinder;
import jdk.javadoc.internal.doclets.toolkit.util.DocFinder.Input;
import jdk.javadoc.internal.doclets.toolkit.util.Utils;

import static com.sun.source.doctree.DocTree.Kind.RETURN;

/**
 * A taglet that represents the @return tag.
 *
 *  <p><b>This is NOT part of any supported API.
 *  If you write code that depends on this, you do so at your own risk.
 *  This code and its internal interfaces are subject to change or
 *  deletion without notice.</b>
 *
 * @author Jamie Ho
 */
public class ReturnTaglet extends BaseTaglet implements InheritableTaglet {

    public ReturnTaglet() {
        super(RETURN.tagName, false, EnumSet.of(Site.METHOD));
    }

    @Override
    public void inherit(DocFinder.Input input, DocFinder.Output output) {
        List<? extends DocTree> tags = input.utils.getBlockTags(input.element, DocTree.Kind.RETURN);
        CommentHelper ch = input.utils.getCommentHelper(input.element);
        if (!tags.isEmpty()) {
            output.holder = input.element;
            output.holderTag = tags.get(0);
            output.inlineTags = input.isFirstSentence
                    ? ch.getFirstSentenceTrees(input.utils.configuration, output.holderTag)
                    : ch.getDescription(input.utils.configuration, output.holderTag);
        }
    }

    @Override
    public Content getTagletOutput(Element holder, TagletWriter writer) {
        Messages messages = writer.configuration().getMessages();
        Utils utils = writer.configuration().utils;
        TypeMirror returnType = utils.getReturnType((ExecutableElement)holder);
        List<? extends DocTree> tags = utils.getBlockTags(holder, name);

        //Make sure we are not using @return tag on method with void return type.
        if (returnType != null && utils.isVoid(returnType)) {
            if (!tags.isEmpty()) {
                messages.warning(holder, "doclet.Return_tag_on_void_method");
            }
            return null;
        }
        if (!tags.isEmpty())
            return writer.returnTagOutput(holder, tags.get(0));
        //Inherit @return tag if necessary.
        List<DocTree> ntags = new ArrayList<>();
        Input input = new DocFinder.Input(utils, holder, this);
        DocFinder.Output inheritedDoc = DocFinder.search(writer.configuration(), input);
        if (inheritedDoc.holderTag != null) {
            CommentHelper ch = utils.getCommentHelper(input.element);
            ch.setOverrideElement(inheritedDoc.holder);
            ntags.add(inheritedDoc.holderTag);
        }
        return !ntags.isEmpty() ? writer.returnTagOutput(holder, ntags.get(0)) : null;
    }
}
