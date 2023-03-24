/*
 * Copyright (c) 2003, 2017, Oracle and/or its affiliates. All rights reserved.
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

package jdk.javadoc.internal.doclets.toolkit;

import java.util.SortedSet;

import javax.lang.model.element.TypeElement;

import jdk.javadoc.internal.doclets.toolkit.util.DocFileIOException;

/**
 * The interface for writing package summary output.
 *
 *  <p><b>This is NOT part of any supported API.
 *  If you write code that depends on this, you do so at your own risk.
 *  This code and its internal interfaces are subject to change or
 *  deletion without notice.</b>
 *
 * @author Jamie Ho
 * @author Bhavesh Patel (Modified)
 */

public interface PackageSummaryWriter {

    /**
     * Get the header for the summary.
     *
     * @param heading Package name.
     * @return the header to be added to the content tree
     */
    public abstract Content getPackageHeader(String heading);

    /**
     * Get the header for the package content.
     *
     * @return a content tree for the package content header
     */
    public abstract Content getContentHeader();

    /**
     * Get the header for the package summary.
     *
     * @return a content tree with the package summary header
     */
    public abstract Content getSummaryHeader();

    /**
     * Adds the table of interfaces to the documentation tree.
     *
     * @param interfaces the interfaces to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addInterfaceSummary(SortedSet<TypeElement> interfaces,
            Content summaryContentTree);

    /**
     * Adds the table of classes to the documentation tree.
     *
     * @param classes the classes to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addClassSummary(SortedSet<TypeElement> classes,
            Content summaryContentTree);

    /**
     * Adds the table of enums to the documentation tree.
     *
     * @param enums the enums to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addEnumSummary(SortedSet<TypeElement> enums,
            Content summaryContentTree);

    /**
     * Adds the table of exceptions to the documentation tree.
     *
     * @param exceptions the exceptions to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addExceptionSummary(SortedSet<TypeElement> exceptions,
            Content summaryContentTree);

    /**
     * Adds the table of errors to the documentation tree.
     *
     * @param errors the errors to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addErrorSummary(SortedSet<TypeElement> errors,
            Content summaryContentTree);

    /**
     * Adds the table of annotation types to the documentation tree.
     *
     * @param annoTypes the annotation types to document.
     * @param summaryContentTree the content tree to which the summaries will be added
     */
    public abstract void addAnnotationTypeSummary(SortedSet<TypeElement> annoTypes,
            Content summaryContentTree);

    /**
     * Adds the package description from the "packages.html" file to the documentation
     * tree.
     *
     * @param packageContentTree the content tree to which the package description
     *                           will be added
     */
    public abstract void addPackageDescription(Content packageContentTree);

    /**
     * Adds the tag information from the "packages.html" file to the documentation
     * tree.
     *
     * @param packageContentTree the content tree to which the package tags will
     *                           be added
     */
    public abstract void addPackageTags(Content packageContentTree);

    /**
     * Adds the tag information from the "packages.html" or "package-info.java" file to the
     * documentation tree.
     *
     * @param contentTree the content tree to which the package content tree will be added
     * @param packageContentTree the package content tree to be added
     */
    public abstract void addPackageContent(Content contentTree, Content packageContentTree);

    /**
     * Adds the footer to the documentation tree.
     *
     * @param contentTree the tree to which the footer will be added
     */
    public abstract void addPackageFooter(Content contentTree);

    /**
     * Print the package summary document.
     *
     * @param contentTree the content tree that will be printed
     * @throws DocFileIOException if there is a problem while writing the document
     */
    public abstract void printDocument(Content contentTree) throws DocFileIOException;

}
