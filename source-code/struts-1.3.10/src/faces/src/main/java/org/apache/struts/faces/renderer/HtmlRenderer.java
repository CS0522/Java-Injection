/*
 * $Id: HtmlRenderer.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.struts.faces.renderer;


import java.io.IOException;
import java.util.Locale;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.context.ResponseWriter;
import javax.servlet.http.HttpSession;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.Globals;


/**
 * <p><code>Renderer</code> implementation for the <code>html</code> tag
 * from the <em>Struts-Faces Integration Library</em>.</p>
 *
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */

public class HtmlRenderer extends AbstractRenderer {


    // -------------------------------------------------------- Static Variables


    /**
     * <p>The <code>Log</code> instance for this class.</p>
     */
    private static Log log = LogFactory.getLog(HtmlRenderer.class);


    // ---------------------------------------------------------- Public Methods


    /**
     * <p>Render the beginning <code>html</code> tag.</p>
     *
     * @param context FacesContext for the current request
     * @param component UIComponent to be rendered
     *
     * @exception IOException if an input/output error occurs while rendering
     * @exception NullPointerException if <code>context</code>
     *  or <code>component</code> is <code>null</code>
     */
    public void encodeBegin(FacesContext context, UIComponent component)
        throws IOException {

        if ((context == null) || (component == null)) {
            throw new NullPointerException();
        }

        Locale currentLocale = getCurrentLocale(context, component);
        String lang = currentLocale.getLanguage();
        boolean validLanguage = ((lang != null) && (lang.length() > 0));

        ResponseWriter writer = context.getResponseWriter();
        writer.startElement("html", component);
        if (isXhtml(component)) {
            // FIXME -- page scope attribute Globals.XHTML_KEY to "true"?
            writer.writeAttribute("xmlns",
                                  "http://www.w3.org/1999/xhtml", null);
        }
        if ((isLocale(component) || isXhtml(component)) && validLanguage) {
            writer.writeAttribute("lang", lang, null);
        }
        if (isXhtml(component) && validLanguage) {
            writer.writeAttribute("xml:lang", lang, null);
        }
        writer.writeText("\n", null);

    }


    /**
     * <p>Render the end of the <code>html</code> element.</p>
     *
     * @param context FacesContext for the request we are processing
     * @param component UIComponent to be rendered
     *
     * @exception IOException if an input/output error occurs while rendering
     * @exception NullPointerException if <code>context</code>
     *  or <code>component</code> is null
     */
    public void encodeEnd(FacesContext context, UIComponent component)
        throws IOException {

        if ((context == null) || (component == null)) {
            throw new NullPointerException();
        }

        ResponseWriter writer = context.getResponseWriter();
        writer.endElement("html");

    }



    // ------------------------------------------------------ Protected Methods


    /**
     * <p>Return the current <code>Locale</code> for this request, creating a
     * new one if necessary.</p>
     *
     * @param context FacesContext for this request
     * @param component UIComponent we are rendering
     */
    protected Locale getCurrentLocale
        (FacesContext context, UIComponent component) {

        // If locale support not requested, just extract one from the request
        if (!isLocale(component)) {
            return (context.getExternalContext().getRequestLocale());
        }

        // Create a new session if necessary
        HttpSession session = (HttpSession)
            context.getExternalContext().getSession(true);

        // Return current locale or a new one that is created
        Locale current = (Locale) session.getAttribute(Globals.LOCALE_KEY);
        if (current != null) {
            return (current);
        }
        current = context.getExternalContext().getRequestLocale();
        session.setAttribute(Globals.LOCALE_KEY, current);
        return (current);

    }



    /**
     * <p>Return the state of the <code>locale</code> attribute.</p>
     *
     * @param component Component to process
     */
    protected boolean isLocale(UIComponent component) {

        Boolean locale = (Boolean) component.getAttributes().get("locale");
        if (locale != null) {
            return locale.booleanValue();
        } else {
            return (false);
        }

    }


    /**
     * <p>Return the state of the <code>xhtml</code> attribute.</p>
     *
     * @param component Component to process
     */
    protected boolean isXhtml(UIComponent component) {

        Boolean xhtml = (Boolean) component.getAttributes().get("xhtml");
        if (xhtml != null) {
            return xhtml.booleanValue();
        } else {
            return (false);
        }

    }


}
